#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
#define INF 1e9+7
int n,m;
int head[100005];//存该顶点的第一条边的编号
//链式前向星
struct Edge {
    int to;
    int Next;
    int weight;
}edge[200005];
int cnt=0;
int dist[100005];//距离数组
int mark[100005];//标记是否已经有最短路径
void addEdge(int u,int v,int w) {//u--weight-->v
    edge[cnt].to=v;
    edge[cnt].weight=w;
    edge[cnt].Next=head[u];//头插法
    head[u]=cnt;//第一条边的编号更新
    cnt++;
}
typedef pair<long long,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> q;
void dijskra_better(int start) {
    for (int i=1;i<=n;i++) {
        dist[i]=INF;
    }
    dist[start]=0;
    pii now;
    now.first=dist[start];
    now.second=start;
    q.push(now);
    int u;
    while (q.size()) {
        now=q.top();
        q.pop();
        int mini=now.first;
        int index=now.second;
        if (mark[index]==1)continue;
        mark[index]=1;
        for (int i=head[index];i!=-1;i=edge[i].Next) {
            u=edge[i].to;
            if (dist[u]>mini+edge[i].weight) {
                dist[u]=mini+edge[i].weight;
                now.first=dist[u];
                now.second=u;
                q.push(now);
            }
        }
    }
}
void dijkstra(int s){//正常方法
    for (int i=1;i<=n;i++) {
        dist[i]=INF;
    }
        dist[s]=0;
        int u;
        for (int i=1;i<=n;i++) {
            int mini=INF;
            int index=-1;
            for (int j=1;j<=n;j++) {
                if (dist[j]<mini&&mark[j]==0) {
                    mini=dist[j];
                    index=j;
                }
            }
            mark[index]=1;
            for (int j=head[index];j!=-1;j=edge[j].Next) {
              u=edge[j].to;
                if (dist[u]>dist[index]+edge[j].weight&&mark[u]==0) {
                    dist[u]=dist[index]+edge[j].weight;
                }
            }
        }
    }

 int main() {
    memset(head,-1,sizeof(head));
    int start;
    scanf("%d %d %d",&n,&m,&start);
    int x,y,w;
    for (int i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&w);
        addEdge(x,y,w);
    }
   dijskra_better(start);
    for (int i=1;i<=n;i++) {
        printf("%d ",dist[i]);
    }
    return 0;
 }
/*
 5 5
 2 3 2
 1 2 3
 1 5 5
 4 5 2
 3 4 3
 1
 */