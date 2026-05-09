#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include <climits>

#define ll long long
using namespace std;
int n,m,cnt;
int head[100005];
struct Edge
{
    int to,w,next;
}edge[500005];
ll dist[100005];
int cur[100005];//判断是否有负环
int vis[100005];//标记i点在队列中
void addEdge(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    cnt++;
}
bool SPFA(int start) {
    for (int i=1;i<=n;i++) {
        dist[i]=INT_MAX;
    }
    int u,k;//记录队头元素，和队头的邻接点
    dist[start]=0;
    vis[start]=1;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        u=q.front();
        q.pop();
        vis[u]=0;//出队更新状态
        for (int i=head[u];i!=-1;i=edge[i].next) {//将合法的邻接点入队
            k=edge[i].to;
            if (dist[k]>dist[u]+edge[i].w) {
                dist[k]=dist[u]+edge[i].w;//更新k点距离
                cur[k]=cur[u]+1;//记录起点到k的边数(最多不会超过n-1条)
                if (cur[k]>n-1)return 0;
                if (vis[k]==0) {//未入队
                    q.push(k);//更新点入队
                    vis[k]=1;
                }

            }
        }
    }
    return 1;
}
int main() {
    memset(head,-1,sizeof(head));
    int start;
    cin>>n>>m>>start;
    int x,y,w;
    for (int i=1;i<=m;i++) {
        cin>>x>>y>>w;
        addEdge(x,y,w);
    }

    int ans=INT_MAX;
    if(SPFA(start)==0)//如果有负环
    {
        printf("%d\n",ans);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%lld ",dist[i]);
    }
    cout<<'\n';

    return 0;
}
/*
 * 1.起点入队，起点标记为入队状态
 * 2.循环出队，队首节点出队，出队节点解除入队标记，
 * 用出队节点更新其邻接点，如果其邻接点被更新了，边权邻接点还未如队，把邻接点入队，邻接点改成入队状态
 */