/*https://leetcode.cn/problems/mice-and-cheese/*/
#include<bits/stdc++.h>
using namespace std;
int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k)
{
    int sum=0;
    int n=reward1.size();
    vector<int>a(n);
    for(int i=0;i<n;i++) {
        a[i]=reward1[i]-reward2[i];//用临时数组存1和2号的差值
        sum+=reward2[i];//先让2号吃掉全部
    }
    sort(a.begin(),a.end());//对差值进行贪心
    for(int i=n-1;i>=n-k;i--) {//加上1号的最大的k个的贡献值(与2号的差值)
        sum+=a[i];
    }
    return sum;
}
int main()
{
    int n,k,x,ans;
    vector<int>r1;
    vector<int>r2;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        r1.push_back(x);
    }

    for(int i=1;i<=n;i++)
    {
        cin>>x;
        r2.push_back(x);
    }
    ans=miceAndCheese(r1,r2,k);
    cout<<ans<<endl;

    return 0;
}