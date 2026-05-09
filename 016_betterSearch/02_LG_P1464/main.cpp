/*https://www.luogu.com.cn/problem/P1025*/
#include<iostream>
#include<cstring>

#define ll long long
using namespace std;
int f[25][25][25];//记忆搜索表，减少重复计算
ll w(ll a,ll b,ll c)
{
    //按照题目要求进行操作，计算过的存入搜索表中，下次可直接使用
    if(a<=0||b<=0||c<=0)return 1;
    else if(a>20||b>20||c>20)
    {
        if(f[20][20][20]!=-1)return f[20][20][20];
        return f[20][20][20]=w(20,20,20);
    }
    else if(a<b&&b<c)
    {
        if(f[a][b][c-1]==-1)f[a][b][c-1]=w(a,b,c-1);
        if(f[a][b-1][c-1]==-1)f[a][b-1][c-1]=w(a,b-1,c-1);
        if(f[a][b-1][c]==-1)f[a][b-1][c]=w(a,b-1,c);

        return f[a][b][c-1]+f[a][b-1][c-1]-f[a][b-1][c];
    }
    else
    {
        if(f[a-1][b][c]==-1)f[a-1][b][c]=w(a-1,b,c);
        if(f[a-1][b-1][c]==-1)f[a-1][b-1][c]=w(a-1,b-1,c);
        if(f[a-1][b][c-1]==-1)f[a-1][b][c-1]=w(a-1,b,c-1);
        if(f[a-1][b-1][c-1]==-1)f[a-1][b-1][c-1]=w(a-1,b-1,c-1);
        return f[a-1][b][c]+f[a-1][b-1][c]+f[a-1][b][c-1]-f[a-1][b-1][c-1];

    }

}

int main()
{
    ll a,b,c,ans;
    memset(f,-1,sizeof(f));//还未搜索过的设置为-1
    while(scanf("%lld %lld %lld",&a,&b,&c))
    {

        if(a==-1&&b==-1&&c==-1)break;
        ans=w(a,b,c);
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,ans);

    }

    return 0;
}