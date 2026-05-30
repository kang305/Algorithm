//https://www.luogu.com.cn/problem/P2758
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
char a[2009];
char b[2009];
int n, m;
int dp[2005][2005];//dp[n][m]=x代表将a[1]--a[n]变成b[1]--b[m]的最少操作次数为x
int main(){
    scanf("%s%s",a+1,b+1);//从下标1开始输入
    n=strlen(a+1);
    m=strlen(b+1);
    //初始化，a字符串前i（包括第i个）个字符至少要通过删除字符i个变成b字符串前0个字符，即a字符串全删没了需要操作i次。
    for(int i=1;i<=n;i++)dp[i][0]=i;
    //初始化，a字符串从0个字符至少要通过添加i个字符变成b字符串前i个字符（包括第i个），即a字符串从0扩充为b字符串需要操作i次。
    for(int j=1;j<=m;j++)dp[0][j]=j;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i]==b[j]) {
                //那么在a前i-1个字符串最少能通过dp[i-1][j-1]次操作转化为b前j-1个字符串的基础上什么都不干，dp[i][j]自然与dp[i-1][j-1]相等。
                dp[i][j]=dp[i-1][j-1];
            }else {
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j]))+1;
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}