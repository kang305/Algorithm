//https://www.luogu.com.cn/problem/P1101
#include<iostream>
using namespace std;
int n;
int c[10000][2],d=0;          //存储所有'y'的位置
int x[9] = {0,1,0,1,-1,0,-1,1,-1};
int y[9] = {0,0,1,1,0,-1,-1,-1,1};
char a[103][103],k[9]=" yizhong";//有效位置[1,7]
bool s[102][102];//检查是否合法

bool dfs(int x,int y,int dx,int dy,int cnt) {//(x,y)沿着向量dx-dy移动，此时是第cnt个
    if (cnt==8) { //已匹配完所有字母[1,7]
        s[x][y]=1;  //(x,y)是cnt-1对应的
        return 1;
    }
    int nx=x+dx,ny=y+dy;    //计算cnt对应位置
    if (nx<1||nx>n||ny<1||ny>n)return 0;  //越界
    //只有当前和所有的递归层都满足才可以进行标记
    if (a[nx][ny]==k[cnt]) {
        if (dfs(nx,ny,dx,dy,cnt+1)) {
            s[x][y]=1;
            return 1;
        }
    }
    return 0;
}

int main() {
    int i,j,k;
    cin>>n;
    // 读入矩阵，并记录所有 'y' 的位置
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            cin>>a[i][j];
            if (a[i][j]=='y') {
                c[++d][0]=i;
                c[d][1]=j;
            }
        }
    }

    while(d){//检查每个y的8个方向
        i=c[d][0];
        j=c[d][1];
        for (k=1;k<=8;k++) {
            int ni=i+x[k],nj=j+y[k];
            if (ni>=1&&ni<=n&&nj>=1&&nj<=n&&a[ni][nj]=='i') {//检查第二个位置
                if (dfs(ni,nj,x[k],y[k],3)){
                    s[i][j]=1;
                }
            }
        }
        d--;
    }

    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            if (s[i][j])cout<<a[i][j];
            else cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}