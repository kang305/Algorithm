/*https://www.luogu.com.cn/problem/P8693#ide*/
#include<iostream>
#include<queue>
using namespace std;
char map[304][304];
int n,k;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
struct people {
    int x,y;//中心位置的坐标
    int t;//时间
    int s;//身材半径，中心点向外延伸的距离2 1 0
};
int vis[304][304];//检查是否走过
queue<people> q;
bool check(int nx,int ny,int r) {//检查是否可以移动
    if (vis[nx][ny]==1) {//检查下一个位置是否走过
        return 0;
    }
    //检查身材内是否合法，以及会不会超过边界
    for (int i=nx-r;i<=nx+r;i++) {
        for (int j=ny-r;j<=ny+r;j++) {
            if (i<1||i>n||j<1||j>n||map[i][j]=='*') {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>map[i][j];
        }
    }
    vis[3][3]=1;//标记初始位置
    q.push( people{3,3,0,2});//把起始位置入队
    int r;//临时保存半径的变量
    while(!q.empty()) {//BFS
        people now=q.front();
        q.pop();
        if (now.x==n-2&&now.y==n-2) {//走到终点
            cout<<now.t<<endl;//输出答案位置的时间
            break;
        }
        if (now.s!=0) {//情况1:还未变成最瘦1*1的情况，保持原地不动，t=t+1
            if (now.t+1<k) {//不同时间的身材半径
                r=2;
            }else if (now.t+1<2*k) {
                r=1;
            }else {
                r=0;
            }
            q.push(people{now.x,now.y,now.t+1,r});//不动,时间改变和对应的身材半径入队
        }
        people Next;
        for (int i=0;i<4;i++) {//情况2:中心的上下左右,t=t+1
            Next.x=now.x+dx[i];
            Next.y=now.y+dy[i];
            if (check(Next.x,Next.y,now.s)) {//检查上下左右位置是否可走
                vis[Next.x][Next.y]=1;//标记下一个位置
                Next.t=now.t+1;//时间增加
                if (now.t+1<k) {//更新身材
                    Next.s=2;
                }else if (now.t+1<2*k) {
                    Next.s=1;
                }else {
                    Next.s=0;
                }
                q.push(Next);//把下一个位置入队
            }
        }
    }
    return 0;
}