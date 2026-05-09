#include<iostream>
#include<string>
#include<queue>
using namespace std;
//有向图，不保证无环，需要判断
int n,m;
struct edge {
    int to,next;
}e[100005];
int cnt=0;
int head[105];
int indegree[105];
int topo[105],k=0;//k是topo数组的下标
void addedge(int u,int v) {
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
    cnt++;
}
bool kahn() {
    queue<int> q;//用队列存入度为0的点
    for(int i=1;i<n;i++) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    int x,y;
    while(!q.empty()) {
        x=q.front();
        q.pop();
        topo[++k]=x;//从下标1开始存
        for(int i=head[x];i!=-1;i=e[i].next) {
            y=e[i].to;//保存x邻接点下标
            indegree[y]--;//减少入度
            if(indegree[y]==0) {//入度为0，y入队
                q.push(y);
            }
        }
    }
    if (k==n) return 1;//无环
    else return 0;//有环
}
int main() {
   cin>>n>>m;
   memset(head,-1,sizeof(head));
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        addedge(u,v);
        indegree[v]++;//入度点加1，即边的终点
    }
    if(kahn()==1) {
        for(int i=1;i<=n;i++) {
            cout<<topo[i]<<" ";
        }
        cout<<endl;
    }else {
        printf("have a circulal");
    }
    return 0;
}