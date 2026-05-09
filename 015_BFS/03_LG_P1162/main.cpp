#include<iostream>
#include<queue>

using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int n;
int map[39][39];
int vis[39][39];
typedef pair<int,int> pii;
queue<pii> q;
void bfs(int x,int y) {
    pii now,next;
    vis[x][y]=1;//入队标记
    now.first=x;
    now.second=y;
    q.push(now);
    while(!q.empty()) {
        next=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx=next.first+dx[i];
            int ny=next.second+dy[i];
            //先检查位置是否合法，边界0的连通块，是否标记
            if (nx>=1&&nx<=n&&ny>=1&&ny<=n&&map[nx][ny]==0&&vis[nx][ny]==0) {
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }

    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>map[i][j];
            if(map[i][j]==1) {
                vis[i][j]=1;
            }
        }
    }
    for (int i=1;i<=n;i++) {//对竖边界进行检查
        if (map[i][n]==0&&vis[i][n]==0)bfs(i,n);//检查右边界
        if (map[n][i]==0&&vis[n][i]==0)bfs(n,i);//检查底部
        if (map[i][1]==0&&vis[i][1]==0)bfs(i,1);//检查顶部
        if (map[1][i]==0&&vis[1][i]==0)bfs(1,i);//检查左边界
    }
    //输出
    for (int i = 1; i <= n; i++) {
        for (int j=1; j <= n; j++) {
            if (map[i][j] == 1) {
                cout << 1 << " ";
            } else if (vis[i][j] == 1) {
                cout << 0 << " ";
            } else {
                cout << 2 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}