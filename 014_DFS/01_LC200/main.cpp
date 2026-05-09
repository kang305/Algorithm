/*https://leetcode.cn/problems/number-of-islands/description/*/
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char> >& grid,int i,int j)
{
    int n=grid.size();//行数
    int m=grid[0].size();//列数
    grid[i][j]='0';//把已经计算过的位置标记成水，防止重复
    //对陆地的上下左右进行搜索i的所有连通块
    if (i-1>=0&&grid[i-1][j]=='1')dfs(grid,i-1,j);
    if (j-1>=0&&grid[i][j-1]=='1')dfs(grid,i,j-1);
    if (i+1<n&&grid[i+1][j]=='1')dfs(grid,i+1,j);
    if (j+1<m&&grid[i][j+1]=='1')dfs(grid,i,j+1);
}

int numIslands(vector<vector<char> >& grid)
{
    int n=grid.size();//行数
    int m=grid[0].size();//列数
    int ans=0;
    for(int i=0;i<n;i++) {//每个格子进行遍历
        for(int j=0;j<m;j++) {
            if(grid[i][j]=='1') {//如果是陆地搜索他的连通块
                ans++;//整个连通块是一个岛屿
                dfs(grid,i,j);
            }
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char> >g(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>g[i][j];
        }
    }
    int ans=numIslands(g);
    cout<<ans<<endl;


    return 0;
}