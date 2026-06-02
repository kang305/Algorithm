//https://www.luogu.com.cn/problem/P4170
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<climits>
using namespace std;
char a[55];
int dp[55][55];//区间[i,j]最少涂色次数
int n;
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++) {
        //初始状态:区间长度只为1
        dp[i][i]=1;
    }
    int j;//右端点
    //枚举区间长度：该区间有多少个点
    for (int len=2;len<=n;len++) {//从短区间开始计算(长区间是由短区间得到的)
        //枚举左端点
        for(int i=1;i+len-1<=n;i++) {//左端点+区间长度-1(右端点)不能超过总长，右端点可由左端点+区间长度-1得到
            j=i+len-1;//右端点  [i,j]闭区间
            if (a[i]==a[j]) {//区间首尾相同
                dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
            }
            else {
                for(int k=i;k<j;k++) {//枚举分割点，k!=j不然右区间变成[j+1,j]
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }

    cout<<dp[1][n];
    return 0;
}

/*
if(a[i]==a[j]){//首尾相同，可以一次涂完首尾，去除头或者去除尾
dp[i][j]=min(dp[i+1][j],dp[i][j-1])
}
else{
枚举分割点k
dp[i][j]=min(dp[i][k]+dp[k+1][j])//不同分割点的最小值，区间dp
}
*/

