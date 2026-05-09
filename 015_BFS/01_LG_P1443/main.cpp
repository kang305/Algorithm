/*https://www.luogu.com.cn/problem/P1443#ide*/
#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;
typedef pair<int,int> pii;//数对表示坐标
int ans[404][404];
int vis[404][404];//标记数组
//当前马可以走的位置(日字型)
int dx[8]={2,2,-2,-2,1,1,-1,-1};
int dy[8]={1,-1,1,-1,2,-2,2,-2};
queue<pii> q;
int main()
{
    int n,m,x,y;
    int nx, ny;
    cin>>n>>m>>x>>y;
    memset(ans,-1,sizeof(ans));
    ans[x][y]=0;//起始位置为0，并标记
    vis[x][y]=1;
    pair<int,int> p,next_p;//记录队头和下一个合理的位置
    p.first=x;
    p.second=y;
    q.push(p);//第一个元素入队
    while(!q.empty()) {//广度遍历，将当前元素可到且还未走过的入队
        p=q.front();
        q.pop();
        for(int i=0;i<8;i++) {//检查可以走的位置
            nx=p.first+dx[i];
            ny=p.second+dy[i];
            if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny]==0) {//在棋盘内且未走过
                ans[nx][ny]=ans[p.first][p.second]+1;//到(nx,ny)的最短次数是前一个到它的+1
                vis[nx][ny]=1;
                //将当前找到的入队
                next_p.first=nx;
                next_p.second=ny;
                q.push(next_p);
            }
        }
    }
    for(int i=1;i<=n;i++) {//输出
        for(int j=1;j<=m;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}