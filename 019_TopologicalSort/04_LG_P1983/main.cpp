//https://www.luogu.com.cn/problem/P1983
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include <climits>
#include<utility>
#define ll long long
/*level 临时停靠站的级别都要大于等于停靠的最小级别
  level 非停靠站＜level停靠站
*/
using namespace std;
int n,m;
vector<int>graph[1003];
int vis[1003];//每趟停靠的站
int flag[1005];//标记是否停靠
int ind[1005];//入度记录
int cnt;
int check[1005][1005];//判断两点之间是否已经建立边，check[i][j]==1  已经有一条i————>j
int level[1005];//每个站点的级别
void kahn(){
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
            level[i]=1;//入度为0的点，全程未停靠的站，级别为1
        }
    }
    int x,y;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++)
        {
            y=graph[x][i];
            level[y]=max(level[y],level[x]+1);
            ind[y]--;
            if(ind[y]==0)q.push(y);
        }

    }
}
int main()
{
    cin>>n>>m;
    int num;
    for(int i=1;i<=m;i++) {//建图
        cin>>num;
        memset(flag,0,sizeof(flag));//每趟停靠点不同，初始化标记数组
        for(int j=1;j<=num;j++) {
            cin>>vis[j];
            flag[vis[j]]=1;//在vis[j]上停靠过
        }
        for(int j=vis[1];j<=vis[num];j++) {//枚举该线路之间所有的站
            if(flag[j]==1)continue;//停靠过，跳过该点
            for(int k=1;k<=num;k++) {//枚举该趟中间的停靠站
                if (check[j][vis[k]]==0) {//还未停靠站和停靠站之间未建边
                    graph[j].push_back(vis[k]);//将停靠的站加入未停靠站的邻接表里(未停靠站指向停靠站)
                    check[j][vis[k]]=1;//停靠站入邻接表后进行标记
                    ind[vis[k]]++;//停靠站入度++
                }
            }
        }
    }
    kahn();
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,level[i]);
    }
    printf("%d\n",ans);

    return 0;
}