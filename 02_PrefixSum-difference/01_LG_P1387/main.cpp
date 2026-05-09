/*https://www.luogu.com.cn/problem/P1387#ide*/
#include<bits/stdc++.h>
using namespace std;

int n[105][105];      // 存储原始矩阵
int sum[105][105];    // 前缀和数组
int ans=0;            // 存储最大正方形边长，初始化为0

int main() {
    int a,b;          // a为行数，b为列数
    cin>>a>>b;        // 输入行数和列数

    // 读取矩阵，从(1,1)开始存储
    for(int i=1;i<=a;i++) {
        for(int j=1;j<=b;j++) {
            cin>>n[i][j];   // 读入每个元素的值（0或1）
        }
    }

    // 计算二维前缀和
    sum[1][1]=n[1][1]; // 第一个元素的前缀和就是它本身

    // 计算前缀和数组，注意这里是从(1,1)开始计算的
    for(int i=1;i<=a;i++) {
        for(int j=1;j<=b;j++) {
            // 当前前缀和 = 上方矩形和 + 当前行当前列的值 + 左方矩形和 - 左上方矩形和（因为加了两次）
            // 注意：这里sum[i-1][j]和sum[i][j-1]已经包含了sum[i-1][j-1]，所以减去一个
            sum[i][j]=sum[i-1][j]+n[i][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }

    int l=1,x,y;   // l为当前检查的正方形边长，x和y用于计算正方形的左上角坐标

    // 从边长为1开始，直到可能的最大边长（即a和b中的较小值）
    while(l<=min(a,b)) {
        // 遍历所有可能的右下角坐标，因为正方形边长为l，所以右下角行至少为l，列至少为l
        for(int i=l;i<=a;i++) {
            for(int j=l;j<=b;j++) {
                x=i-l+1;  // 正方形的左上角行坐标
                y=j-l+1;  // 正方形的左上角列坐标
                // 计算以(x,y)为左上角，(i,j)为右下角的子矩阵的和
                // 如果这个和等于l*l，说明这个正方形内全是1（因为每个元素都是1，和为l*l）
                if (sum[i][j]-sum[i][y-1]-sum[x-1][j]+sum[x-1][y-1]==l*l) {
                    ans=max(ans,l);  // 更新最大边长
                }
            }
        }
        l++;  // 增加边长，继续检查
    }

    cout<<ans<<endl;  // 输出最大边长
    return 0;
}