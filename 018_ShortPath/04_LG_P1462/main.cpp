/*https://www.luogu.com.cn/problem/P1462*/
#include<iostream>
#include<utility>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> q;
int n,m,b;
int flag[10005];//标记数组
int head[10005];//节点顶点数组
struct Edge {
    int to,w,next;
}edge[100005];//边集数组
int cnt=0;
int dist[10005];//距离数组
int spend[10005];//各城市花费数组
//链式前向星
void addEdge(int u,int v,int w) {//u-->v
    edge[cnt].to=v;
    edge[cnt].w=w;
    //头插法
    edge[cnt].next=head[u];
    head[u]=cnt;
    cnt++;
}
bool Dijkstra(int s,int Max) {//堆优化dijs算法
    if (Max<spend[s])return 0;//起点的路费大于规定当前的最大
    //每次都需要初始化距离和标记数组，在新限制重新计算最短路
    memset(dist,0x3f,sizeof(dist));
    memset(flag,0,sizeof(flag));
    dist[s]=0;
    pii now;
    now.first=dist[s];
    now.second=s;
    q.push(now);//起始节点入队
    while(!q.empty()) {
        now=q.top();
        q.pop();
        int mini=now.first;
        int index=now.second;
        if (flag[index]==1)continue;
        flag[index]=1;
        for (int i=head[index];i!=-1;i=edge[i].next) {//对堆顶节点的邻接点进行遍历
            int u=edge[i].to;
            int w=edge[i].w;
            if (spend[u]<=Max&&dist[u]>mini+w){//当前的路费大于规定的节点不计入最短路
                dist[u]=mini+edge[i].w;
                now.first=dist[u];
                now.second=u;
                q.push(now);
            }
        }
    }
    return dist[n]<=b;
}
int main() {

    cin>>n>>m>>b;
    memset(head,-1,sizeof(head));
    int left=0x3f3f3f3f,right=-0x3f3f3f3f;
    for (int i=1;i<=n;i++) {
        scanf("%d",&spend[i]);
        left=min(left,spend[i]);//最小值是最小的收费城市
        right=max(right,spend[i]);//最大值同上
    }

    int u,v,w;
    for(int i=0;i<m;i++) {

        scanf("%d %d %d",&u,&v,&w);
        if (u==v)continue;//去除自己指向自己
        //双向
        addEdge(u,v,w);//u->v
        addEdge(v,u,w);//v->u
    }
   //判断1是否可以到n
    bool mark=Dijkstra(1,0x3f3f3f3f);//如果在规定血量到达不了终点
    if(mark==0) {
        printf("AFK\n");
        return 0;
    }
    //二分求答案
    int mid=0;
    int ans=0;
    while (left<=right) {
        mid=(left+right)/2;
        if (Dijkstra(1,mid)==1) {//在规定最大单次路费为mid的情况下，可以到达终点
            ans=mid;
            right=mid-1;//检查更小的mid,最小化最大值
        }else left=mid+1;//mid太小了满足不了在单次最大值<mid的情况到达终点，要扩大mid来找最短路
    }
    printf("%d\n",ans);
    return 0;
}