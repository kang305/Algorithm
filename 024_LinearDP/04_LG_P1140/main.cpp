//https://www.luogu.com.cn/problem/P1140
#include<iostream>
#include<algorithm>
using namespace std;
int la,lb,a[110],b[110];
int dp[110][110];//dp[i][j]代表第一个字符串前i个和第二个字符串前j个最大相似度
int d[6][6]=
{
    {0,0,0,0,0,0},
    {0,5,-1,-2,-1,-3},
    {0,-1,5,-3,-2,-4},
    {0,-2,-3,5,-2,-2},
    {0,-1,-2,-2,5,-1},
    {0,-3,-4,-2,-1,0}
};
int main()
{
    //输入1-A  2-C  3-G  4-T
    cin>>la;
    for(int i=1;i<=la;i++)
    {
        char t;
        cin>>t;
        switch(t)
        {
            case'A':
                a[i]=1;break;
            case'C':
                a[i]=2;break;
            case'G':
                a[i]=3;break;
            case'T':
                a[i]=4;break;
        }
    }
    cin>>lb;
    for(int i=1;i<=lb;i++)
    {
        char t;
        cin>>t;
        switch(t)
        {
            case'A':
                b[i]=1;break;
            case'C':
                b[i]=2;break;
            case'G':
                b[i]=3;break;
            case'T':
                b[i]=4;break;
        }
    }
    //初始化
    dp[0][0]=0;
    for(int i=1;i<=la;i++)
        //第一个字符串只和空白匹配的相似度
            dp[i][0]=dp[i-1][0]+d[a[i]][5];
    for(int j=1;j<=lb;j++)
        //第二个字符串只和空白匹配的相似度
            dp[0][j]=dp[0][j-1]+d[5][b[j]];

    for(int i=1;i<=la;i++) {
        for(int j=1;j<=lb;j++) {
            //状态转移公式:讨论当前位置两个字符串最后一个字符如何配对 取max
            //1.Ai-1和Bj-1匹配 + i和j匹配
            //2.Ai-1和Bj匹配 + i和空白匹配
            //3.A1和Bj-1匹配 + j和空白匹配
            dp[i][j]=max(dp[i-1][j-1]+d[a[i]][b[j]],
                max(dp[i-1][j]+d[a[i]][5],dp[i][j-1]+d[5][b[j]]));
        }
    }
    cout<<dp[la][lb]<<endl;
    return 0;
}