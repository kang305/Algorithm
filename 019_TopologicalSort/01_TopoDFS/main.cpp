#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include <climits>
#include<utility>
#define ll long long
using namespace std;
//有向图 时间复杂度O(n+m)
int n,m;//n<100  1~~n
struct edge
{
    int to,next;
}e[10005];
int head[105];
int cnt;
int vis[105];
int check;//查看环是在哪个点
stack<int>topo;//先进后出，从拓扑后面开始存数据
void DFS_DAG(int x) {//递归的最后一层会找到出度为0的点,压入栈中，返回上一层
    vis[x]=1;//标记为已经访问过
    int y;
    for(int i=head[x];i!=-1;i=e[i].next) {
        y=e[i].to;
        if(vis[y]==0) {//为被标记的点进行DFS
            DFS_DAG(y);
        }
    }
    topo.push(x);//返回时入栈，记录拓扑序列
}
/*
 扩展标记数组
vis[i]=0   还未走过/还未遍历过
      =1   该点及其后面所有的点已经访问完了------>回溯时标记为1
      =2   这个点走过一次了 现在正在遍历该点后面的点--->第一次走到该点时标记为2
*/
int flag=0;//标记是否有环,环不会影响dfs，所以需要判断
void DFS(int x) {//判断是否有环
    vis[x]=2;//第一次访问
    int y;
    for(int i=head[x];i!=-1;i=e[i].next) {
        y=e[i].to;
        if (vis[y]==2) {//有环,且y就在环上
            flag=1;
            check=y;
            return;//有环，退出
        }
        else if(vis[y]==0) {//为被标记的点进行DFS
            DFS(y);
            if (flag==1) {//y不在环上，但是y后面的点可能是在环上，如果返回时，flag=1,后面有环，退出
                return;
            }
        }

    }
    topo.push(x);//返回时入栈，记录拓扑序列
    vis[x]=1;//后面的元素合法无环，可将x压入栈中
}
void add(int u,int v)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}


int main(){
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    int u,v;
    for(int i=0;i<m;i++) {
        cin>>u>>v;
        add(u,v);
    }
for(int i=1;i<=n;i++) {
    if(vis[i]==0) {//对未被访问的点就行DFS
        DFS(i);
    }
}
    if (flag==1) {
        printf("-1  %d\n",check);
    }else {
        while(!topo.empty()) {
            cout<<topo.top()<<" ";
            topo.pop();
        }
    }
    return 0;
}
/*有环
5 5
1 2
2 4
3 2
4 3
4 5
*/