//https://www.luogu.com.cn/problem/P1902
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m;
int p[1005][1005];
bool vis[1005][1005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
typedef pair<int,int> pii;
bool check(int mid) {
    memset(vis, 0, sizeof(vis));
    queue<pii> q;
    // 从第一行所有列出发
    for (int j = 1; j <= m; j++) {//将第一行的元素全部入队逐个检查模拟
        vis[1][j]=1;
        q.push(make_pair(1, j));
    }
    while (!q.empty()) {
        pii now=q.front();
        q.pop();
        int x=now.first,y=now.second;
        if (x==n) return 1; //到达最后一行就可以退出
        for (int i = 0; i < 4; i++) {
            int nx=x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) {//超过边界
                continue;
            }
            if (!vis[nx][ny]&&p[nx][ny]<=mid) {//未被访问，且小于设置的最大值
                vis[nx][ny]=true;//该点合法
                q.push({nx,ny});
            }
        }
    }
    return false;
}

int main() {
    cin>>n>>m;
    int Max=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>p[i][j];
            if (p[i][j]>Max)Max=p[i][j];
        }
    }
    int L=0, R=Max, ans=Max;
    while(L<=R) {
        int mid=(L+R)/2;
        if (check(mid)){
            ans=mid;
            R=mid-1;
        } else{
            L=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}