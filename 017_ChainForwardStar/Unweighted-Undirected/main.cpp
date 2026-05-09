#include <iostream>
#include <vector>
using namespace std;
//无权无向图-->二维数组vector
int n,m;//n个点，m条边
struct Edge {
    int near;//临接点
    int weight;//权值
};
vector<vector<Edge>>graph;//利用二维动态数组模拟临接表
//基于无权无向临接表的DFS
int vis[109]={0};//标记数组->检查是否访问过
void dfs(int x) {
    if (vis[x]==1) {
        return;
    }
    printf("%d ",x);
    vis[x]=1;
    int y;
    for(int i=0;i<graph[x].size();i++) {
        y=graph[x][i].near;//找x节点的邻接点
        dfs(y);
    }
}
int main() {
    cin>>n>>m;
    graph.resize(n+1);
    int x,y,weight;//起点，终点，权值
    for(int i=1;i<=m;i++) {
        cin>>x>>y>>weight;
        graph[x].push_back(Edge(y,weight));
        graph[y].push_back(Edge(x,weight));
    }
    //DFS
    for(int i=1;i<=n;i++) {
        if(vis[i]==0) {
            dfs(i);
        }
    }
}