//https://www.luogu.com.cn/problem/P1113
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include <climits>
#include<utility>
#define ll long long
using namespace std;
int n;
struct edge
{
    int to,next;
}e[1000005];
int h[10005];
int ind[10005];
int cnt;
int Time[10005];//每个点需要的时间
int finish[10005];//每个点的完成时间
void add(int u,int v)//u-->v
{
    e[cnt].to=v;
    e[cnt].next=h[u];
    h[u]=cnt++;
}
void kahn(){
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(ind[i]==0) {
            q.push(i);
            finish[i]=Time[i];//没有前置工作的任务，就是其花费时间
        }
    }
    int x,y;
    while(!q.empty()) {
        x=q.front();
        q.pop();
        for (int i=h[x];i!=-1;i=e[i].next) {
            y=e[i].to;
            finish[y]=max(finish[y],finish[x]+Time[y]);//更新y的完成时间，finish[y]有time[y]和最大的前置杂物决定
            ind[y]--;
            if(ind[y]==0) {
                q.push(y);
            }
        }
    }

}
int main()
{
    scanf("%d",&n);
    int x,y;//前置杂物，当前事件
    memset(h,-1,sizeof(h));
    for(int i=1;i<=n;i++) {//建图
        scanf("%d",&y);
        scanf("%d",&Time[y]);
        while (1) {
            scanf("%d",&x);
            if(x==0)break;
            add(x,y);//x是前置事件x-->y
            ind[y]++;//x指向y,y的入度加1
        }
    }
    kahn();
    int ans=-1;
    for(int i=1;i<=n;i++) {
        ans=max(ans,finish[i]);
    }
    printf("%d\n",ans);
    return 0;
}