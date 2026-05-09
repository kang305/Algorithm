#include<iostream>
#include<utility>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> q;
int n,m;
int flag[1005];
int head[1005];
struct Edge {
    int to,w,next;
}edge[20005];
int cnt=0;
int dist[1005];
int stop[1005];
void addEdge(int u,int v,int w) {//u-->v
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    cnt++;
}
void solve(int s) {//堆优化dijs算法
    int u,v,w;
    dist[s]=0;
    pii now;
    now.first=dist[s];
    now.second=s;
    q.push(now);
    while(!q.empty()) {
        now=q.top();
        q.pop();
        int mini=now.first;//存距离
        int index=now.second;//存出队元素下标
        u=now.second;
        if (flag[u]==1)continue;
        flag[u]=1;
        for (int i=head[u];i!=-1;i=edge[i].next) {
            v=edge[i].to;
            w=edge[i].w;
            if (flag[v]==0&&dist[v]>dist[u]+w) {//为被标记，邻接点距离可以被松弛
                dist[v]=dist[u]+w;
                now.first=dist[v];
                now.second=v;
                q.push(now);//将更新的数据压入堆中
            }
        }
    }
}
int main() {

    cin>>n>>m;
    memset(head,-1,sizeof(head));
    memset(dist,0x3f,sizeof(dist));
    for (int i=1;i<=n;i++) {
        scanf("%d",&stop[i]);
    }
    int u,v,w;
    for(int i=0;i<m;i++) {

        scanf("%d %d %d",&u,&v,&w);
        addEdge(u,v,w+stop[v]);//添加路径的时候把终点的停留时间算上
        addEdge(v,u,w+stop[u]);
    }
    solve(1);
    printf("%d\n",dist[n]-stop[n]);//最后的点多加了停留时间
    return 0;
}