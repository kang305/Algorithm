#include<iostream>
using namespace std;
int n;
int Max=0;
int cow[50009];
int sum[50009];
//同余的最大子区间是最后一个-第一个的长度(如果只有一个，first和last都是它)
int first[7];//记录余数为i，第一个出现的前缀和
int last[7];//最后一个出现的前缀和
int main() {
    cin>>n;
    sum[0]=0;
    for(int i=1;i<=n;i++) {
        cin>>cow[i];
        sum[i]=(sum[i-1]+cow[i])%7;//计算前缀和的余数
    }
    for (int i=n;i>=1;i--) {//从后往前检查，找到每个余数出现的第一个索引
        first[sum[i]]=i;
    }
    first[0]=0;//将第一个出现余数为0的索引设置为0
    for (int i=1;i<=n;i++) {//找到每个余数出现的最后一个索引
        last[sum[i]]=i;
    }
    for (int i=0;i<=6;i++) {//在每个同余的区间找到最大的子区间
        Max=max(last[i]-first[i],Max);
    }
    cout<<Max;
    return 0;
}