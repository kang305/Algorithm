#include <iostream>
#include <vector>
using namespace std;
//有权无向图-->静态链表
int n,m;//n个点，m条边
int head[109];
struct Edge {//存的是有向边，无向图看作两个有向边
    int to;//边的终边
    int weight;//权值
    int Next;//同起点下一条边的编号
}edge[10005];//最多有n*（n-1）条边
int cnt=0;//记录边集数组的下标
//基于有权无向图链式前向星的DFS
int vis[109];//标记数组存访问过的节点
void DFS_DAG(int x) {
    if (vis[x]==1)return;//递归遇到已经标记过的跳过该层
    printf("%d",x);
    vis[x]=1;
    int tmp;//保存邻接点
    for(int i=head[x];i!=-1;i=edge[i].Next) {//枚举x的所有出边，找x的邻接点
       tmp=edge[i].to;//找到i的邻接点j
        DFS_DAG(tmp);//递归j
    }
}
void addEdge(int x,int y,int w) {//在边集数组添加x->y权值为w的边
    edge[cnt].to=y;
    edge[cnt].weight=w;
    //模拟链表头插法
    edge[cnt].Next=head[x];
    head[x]=cnt;//边集数组的下标
    cnt++;//下一条边的编号
}

int main() {
   memset(head,-1,sizeof(head));//将所有节点的第一个出边初始化为-1
    cin>>n>>m;//n个点，m条边
    int x,y,w;
    for(int i=1;i<=m;i++) {
        cin>>x>>y>>w;
        //当作两次有向边存
        addEdge(x,y,w);
        addEdge(y,x,w);
    }
    for(int i=1;i<=n;i++) {
        if (vis[i]==0) {//未访问过
            DFS_DAG(i);
        }
    }
    return 0;
}