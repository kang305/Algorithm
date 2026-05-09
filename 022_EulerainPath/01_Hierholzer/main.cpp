#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
//无向半欧拉图，找欧拉路径
int n, m, cnt;
const int maxn = 105;//最多的点数
const int maxm = 10005;//最多的边数

struct edge {
    int v, next;//当前顶点，下一个顶点
    bool visited;//该条边是否遍历过
}e[maxm*2];

int head[maxn];
int d[maxn];//各点的度
stack<int> ansv;//存储结果的点，并输出
void add(int x, int y) {
    e[cnt].v=y;
    e[cnt].visited=false;
    e[cnt].next=head[x];
    head[x]=cnt;
    cnt++;
}


void DFS(int u) {//时间复杂度O(m*(n+m))
    for (int i = head[u]; i != -1; i = e[i].next) {//遍历当前点点每一条邻接边
        if (e[i].visited == true)continue;//走过的边直接跳过
        e[i].visited = e[i ^ 1].visited = true; //正反边都标记
        DFS(e[i].v);
    }
    ansv.push(u);//DFS向上返回的时候将答案记录
}


//弧优化：真的删掉边 不会重复判断，时间复杂度变为O（n+m）
void DFS_better(int u) {
    for (int i = head[u]; i != -1; i = head[u]){//不需要下次循环指向下一条边
        if (e[i].visited == true)//这个边已经被走过了
        {
            head[u]=e[i].next;//将边直接从链式前向星中删除
            continue;
        }
        e[i].visited = e[i ^ 1].visited = true; //正反两条边都标记
        DFS_better(e[i].v);
    }
    ansv.push(u);
}

void DFS_better2(int u) {
    while (head[u] != -1) {
        int i = head[u];
        head[u] = e[i].next;
        if (e[i].visited) continue;
        e[i].visited = e[i ^ 1].visited = true;
        DFS_better2(e[i].v);
    }
    ansv.push(u);
}
int main() {
    int x = 0, y = 0;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    for (int i = 1; i <=m; i++) {
        scanf("%d%d", &x, &y);
        //无向图，正反各建一次边
        add(x, y);
        add(y, x);
        //统计度
        d[x]++;
        d[y]++;
    }
    int st=1;//起点
    for(int i=1;i<=n;i++){
        if(d[i]%2==1)//度为奇数的点做起点，找不到就让1做起点
        {
            st=i;
            break;
        }
    }
    DFS_better(st);//从起点进行DFS

    while (!ansv.empty() ) {//出栈
        cout << ansv.top() << " ";
        ansv.pop();
    }
    return 0;

}