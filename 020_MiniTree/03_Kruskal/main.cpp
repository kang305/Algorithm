#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include <climits>
#include<utility>
using namespace std;
const int MAX = 110; // 最大顶点数
const int maxm = 10010; // 最大边数
struct Edge {// 使用结构体储存每一条边，便于排序
    int u, v, w; // 表示有一条 (u,v) 的无向边，边权为 w
} e[maxm+5];
int cnt;// 用于边集数组计数
void addEdge(int u, int v, int w){ // 加入一条无向边
    ++cnt;
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
}
int father[MAX]; // 并查集相关
int find(int x) {
    return x == father[x] ? x : father[x] = find(father[x]); // 路径压缩
}
int n,m; // 顶点数 边数
bool cmp(const Edge &a, const Edge &b){//按照边权排序
    return a.w < b.w;
}
int Kruskal() { // Kruskal 算法核心过程
    for (int i = 1; i <= n; i++) {
        father[i] = i; // 初始化并查集
    }
    sort (e + 1, e + cnt + 1, cmp);
    int sum = 0;
    for (int i = 1; i <= cnt; i++) {
        int u = e[i].u;
        int v = e[i].v;
        u = find(u);
        v = find(v);
        if (u != v) {
            father[u] = v;
            sum += e[i].w;
        }
    }
    return sum;
}
int main(){
    scanf("%d %d",&n,&m);
    int x,y,w;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &x,&y,&w);
        addEdge(x, y, w);
    }

    int ans = Kruskal();
    printf("%d\n",ans);
    return 0;
}
