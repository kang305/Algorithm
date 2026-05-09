#include <iostream>
#include <climits>
#define INF 10000
using namespace std;
//利用边集数组进行存储,带权有向图
int n,m,s;//n个点，m条边,起点s
struct Edge {
    int start;
    int end;
    int weight;
}edge[10005];
int dist[105];
void Ford() {//计算最短路径
    int u,v;//u-->v
    for(int i=1;i<n;i++) {//进行n-1次松弛，对dist数组进行更新
        int flag=0;
        for(int j=1;j<=m;j++) {
            u=edge[j].start;
            v=edge[j].end;
            if (dist[v]>dist[u]+edge[j].weight) {//起点->v当前存点距离>以u作为中转点的距离
                dist[v]=dist[u]+edge[j].weight;
                flag=1;
            }
        }
        if(flag==0) {
            break;
        }
    }
}
void test1() {
    cin>>n>>m;
    int x,y,w;
    for(int i=1;i<=m;i++) {
        cin>>x>>y>>w;
        edge[i].start=x;
        edge[i].end=y;
        edge[i].weight=w;
    }
    for(int i=1;i<=n;i++) {
        dist[i]=INF;
    }
    cin>>s;
    dist[s]=0;
    Ford();
    for(int i=1;i<=n;i++) {
        cout<<dist[i]<<" ";
    }
}
bool BellmanFord() {//判断是否有负环,在n-1轮松弛一定可以算出最短路径
   int u,v;
    int flag;
    for (int i=1;i<=n;i++) {//多进行一次松弛，n次
         flag=0;
        for(int j=1;j<=m;j++) {
            u=edge[j].start;
            v=edge[j].end;
            if (dist[v]>dist[u]+edge[j].weight) {
                dist[v]=dist[u]+edge[j].weight;
                flag=1;
            }
        }
    }
    if (flag==0) {
        return true;
    }else {
        return false;
    }
}
void test2() {
    cin>>n>>m;
    int x,y,w;
    for(int i=1;i<=m;i++) {
        cin>>x>>y>>w;
        edge[i].start=x;
        edge[i].end=y;
        edge[i].weight=w;
    }
    for(int i=1;i<=n;i++) {
        dist[i]=INF;
    }
    cin>>s;
    dist[s]=0;
    bool judge=BellmanFord();
    if(judge) {
        cout<<"Not DAF";
    }else {
        cout<<"DAF";
    }
}
int main() {
    test2();
    return 0;
}
