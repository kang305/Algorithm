//https://www.luogu.com.cn/problem/P1330
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans;
int head[10009];
struct edge {
    int to;
    int next;
}e[200009];//存边无向图
int color[100009];//对每个顶点进行染色，相邻的为不同颜色
int sum[3];//sum[1]和sum[2]记录染色为1或2的个数
int cnt=0;
void addEdge(int u,int v) {
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
    cnt++;
}

bool bfs(int start) {
    queue<int>q;
    sum[1]=1,sum[2]=0;//起点加入染色为1的数组
    color[start]=1;//将起点染色为1
    q.push(start);
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        for (int i=head[u];i!=-1;i=e[i].next) {
            int v=e[i].to;
            if (color[v]==color[u])return 1;//相邻点染色相同
            if (color[v]==0) {//还未染色
                color[v]=color[u]%2+1;//染成与邻接点相反的颜色
                sum[color[v]]++;//在染色为color[v]的总数+1
                q.push(v);
            }
        }
    }
    return 0;
}
int main() {
    memset(head,-1,sizeof(head));

    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }
    for (int i=1;i<=n;i++) {
        if (color[i]!=0)continue;//染过色跳过
        if (bfs(i)) {//未染色检查是否会与邻接点冲突
            cout<<"Impossible";
            return 0;
        }else {
            ans+=min(sum[1],sum[2]);//找染色最少的种类
        }
    }
    cout<<ans<<endl;
    return 0;
}