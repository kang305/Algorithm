#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
const int MAX=5005;
const int INF=0x7fffffff;
int cnt;
struct edge
{
    int u,w,next;
}e[2*MAX];
int head[MAX];//初始化为-1
int dist[MAX];
bool vis[MAX];
int n,m;
void add(int x,int y,int w)		//链式前向星的加点方法
{
    cnt++;
    e[cnt].u=y;
    e[cnt].w=w;
    e[cnt].next=head[x];
    head[x]=cnt;
}
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> q;
int betterPrim() {
    int sum=0;
    int cnt=0;
    for (int i=1;i<=n;i++) {
        dist[i]=INF;
    }
    dist[1]=0;
    pii now;
    now.first=dist[1];
    now.second=1;
    q.push(now);
    int u,w;
    while (!q.empty()) {
        now=q.top();
        q.pop();
        int mini=now.first;
        int index=now.second;
        if (vis[index]==1)continue;
        vis[index]=1;
        sum+=mini;
        cnt++;
        for (int i=head[index];i!=-1;i=e[i].next) {
            u=e[i].u;
            w=e[i].w;
            if (w<dist[u]&&vis[u]==0) {
                dist[u]=w;
                now.first=w;
                now.second=u;
                q.push(now);
            }
        }
    }
    if (cnt<n)return -1;
    return sum;
}
int prim()
{
    for(int i=1;i<=n;i++)dist[i]=INF;
    dist[1]=0;
    vis[1]=1;
    int now=1;
    for(int i=head[now];i!=-1;i=e[i].next)	//链式前向星的遍历方法
    {
        int u=e[i].u;
        dist[u]=min(dist[u],e[i].w);
    }
    int tot=0;
    int sum=0;
    // 循环直到加入n-1条边
    while (tot < n - 1) {
        int mindis = INF;  //记录当前找到的最小距离
        //在所有未加入生成树的节点中，找出距离最小的节点
        for (int i=1;i<=n;i++) {
            if (!vis[i]&&dist[i]<mindis) {
                now=i;
                mindis = dist[i];
            }
        }
        // 如果最小距离仍为无穷大，说明剩余节点与生成树不连通，返回-1
        if (mindis==INF) return -1;
        tot++;               //边数加1
        sum += mindis;
        vis[now] = 1;        //将节点now加入生成树
        //更新新加入节点的邻接点距离
        for (int i = head[now]; i; i = e[i].next) {
            int u = e[i].u;
            if (vis[u]) continue;            // 已在树中的节点跳过
            dist[u] = min(dist[u], e[i].w);    // 用当前边更新距离
        }
    }
    return sum;
}
int main()
{

    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    int ans=betterPrim();
    if(ans==-1)printf("orz");
    else printf("%d",ans);
}


