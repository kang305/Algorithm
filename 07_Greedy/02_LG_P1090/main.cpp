/*https://www.luogu.com.cn/problem/P1090#ide*/
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
int n;
long long ans,x,y;
priority_queue<long long ,vector<long long>,greater<long long> >q;//较小的数优先级高放队列前面
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        q.push(x);
    }
    for(int i=1;i<n;i++){//每次保证最小的两个数出队,循环n-1次
        x=q.top();
        q.pop();
        y=q.top();
        q.pop();
        ans+=x+y;
        q.push(x+y);
    }
    cout<<ans<<endl;
    return 0;
}