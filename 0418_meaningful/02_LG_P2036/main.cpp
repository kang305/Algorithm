//https://www.luogu.com.cn/problem/P2036#ide
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 1e9
using namespace std;
int n,s,b;
int a1[19];
int a2[19];
int v1[19];
int ans=INF;
void dfs(int index,int cnt) {//选择的编号，选择的总数
    if (index>n) {
        if (cnt>0) {
            int sum_s=1;
            int sum_b=0;
            for (int i=1;i<=n;i++) {
                if (v1[i]==1) {
                    sum_s*=a1[i];
                    sum_b+=a2[i];
                }
            }
            ans=min(ans,abs(sum_s-sum_b));
        }
        return;
    }
    v1[index]=0;//去除标记不选
    dfs(index+1,cnt);//不选
    v1[index]=1;//标记index,在递归的时候选择
    dfs(index+1,cnt+1);//选
}
struct node {//已经处理完前index-1个配料，接下来要决策的是第index个配料
    int index;//考虑是否选择index
    int cnt;//选择的数量
    int sum_s;
    int sum_b;
};
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s>>b;
        a1[i]=s;
        a2[i]=b;
    }
    queue<node> q;
    q.push({1,0,1,0});
    while(!q.empty()) {
        node temp=q.front();
        q.pop();
        if (temp.index>n) {//在index>n时队列中有所以组合的可能(考虑完了所以情况)
            if (temp.cnt>0) {//必须选一个，在index>n的情况不断更新
                ans=min(ans,abs(temp.sum_s-temp.sum_b));
            }
            continue;
        }
        q.push({temp.index+1,temp.cnt,temp.sum_s,temp.sum_b});//不选index
        int new_s=temp.sum_s*a1[temp.index];
        int new_b=temp.sum_b+a2[temp.index];
        q.push({temp.index+1,temp.cnt+1,new_s,new_b});//选择index，考虑index+1选不选
    }
    cout<<ans<<endl;
    return 0;
}