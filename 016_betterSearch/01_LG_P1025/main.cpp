/*https://www.luogu.com.cn/problem/P1025#ide*/
#include<iostream>
#include<queue>
//让结果单调即可避免重复
using namespace std;
int n,k;
int ans;
//last上一个位置选的数，step要给第几个位置选数，sum前面选的数的总和
void dfs(int last,int step,int sum) {
    if (step>k) {//检查前k个的总和是否为sum
        if (sum==n) {
            ans++;;
        }
        return;
    }
    for(int i=last;i<=n-k+1;i++) {//只用考虑[1，n-k+1]
        if (sum+i*(k-step+1)>n)break;//进行剪枝操作，如果让后面的都取最小i仍超过范围，舍弃
        dfs(i,step+1,sum+i);
    }
}
int main()
{
    cin>>n>>k;
    dfs(1,1,0);
    cout<<ans<<endl;
    return 0;
}