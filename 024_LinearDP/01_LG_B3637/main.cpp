//https://www.luogu.com.cn/problem/B3637
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int n;
int arr[5004];
int dp[5004];//dp[i]=x,指以arr[i]为结尾的最长上升子序列长度为x
//状态转移方程：a[j]<a[i]-->dp[i]=max(dp[j]+1,dp[i])
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    //初始化状态数组，开始arr[i]的最长上升子序列为自己，长度为1
    for(int i=1;i<=n;i++) {
        dp[i]=1;
    }
    //dp[1]已经固定从2开始更新
    for(int i=2;i<=n;i++) {
        //遍历i之前的dp[j],找可以更新dp[i]的情况
        for(int j=1;j<i;j++) {
            if (arr[j]<arr[i]) {//如果前面的arr[j]<arr[i],arr[i]可以加到arr[j]后面进行更新
                dp[i]=max(dp[j]+1,dp[i]);//找arr[i]前面最大的dp[j]
            }
        }
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++) {//遍历找到最大的就是答案
        if (ans<dp[i]) {
            ans=dp[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}