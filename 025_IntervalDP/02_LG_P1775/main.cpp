//https://www.luogu.com.cn/problem/P1775
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<climits>
using namespace std;
int n;
int arr[309];
int sum[309];
int dp[309][309];//arr[i][j]=x,i~~j合并需要的最小代价
int main(){
    cin>>n;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];//前缀和，算合并需要的代价
        dp[i][i]=0;//只有一个就不需要花费代价
    }
    int j;
    for (int len=2;len<=n;len++) {//枚举区间长度
        for (int i=1;i+len-1<=n;i++) {//枚举左端点
            j=i+len-1;//右端点
            for (int k=i;k<j;k++) {//枚举分割点
                //左边最新代价+右边最小代价+合并两块需要的总代价
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}



