//https://leetcode.cn/problems/qJnOS7/description/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {

    int n=text1.size();
    int m=text2.size();
    int dp[1009][1009]={0};//t1[i]和t2[j]此时的最长公共子序列
    //进行预处理方便进行遍历
    text1=" "+text1;//[1]~~[n]
    text2=" "+text2;//[1]~~[m]

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //当前位置相等
            if(text1[i]==text2[j]){
                dp[i][j]=dp[i-1][j-1]+1;//当前位置最长公共子序列为前一个位置+1
            }
            //当前位置不相等
            else{
                //t1[i]!=t2[j]则两个之一舍弃最后一个字符去和另一个匹配
                //t1[i]=t2[j-1]或t2[j]=t1[i-1]
                //dp[i-1][j-1]包含在dp[i][j-1]或dp[i-1][j]
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);//更新为前面的最大公共子序列
            }
        }

    }
    return dp[n][m];
}
int main()
{
    string s,p;
    cin>>s;
    cin>>p;
    int ans= longestCommonSubsequence(s, p);
    cout<<ans<<endl;

}