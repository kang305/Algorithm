//https://www.luogu.com.cn/problem/P7771
#include<iostream>
#include<cstdio>

#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
int n,m;

int ind[100005];//入度
int outd[100005];//出度
stack<int> ans;//存储结果的点，并输出
vector<int> g[100005];//模拟链式前向星，方便排序找最小字典序
int del[100005];//del[i]==2  从i的第2个邻接点开始访问,类似于无向图的删边操作
void dfs(int x) {
    for (int i=del[x];i<g[x].size();i=del[x]) {
        del[x]=i+1;//删除x的第i个邻接点 即删除x的第i条出边,x的第一条边变成i+1---->弧优化
        dfs(g[x][i]);//访问x的第i个邻接点
    }
    ans.push(x);
}
int main() {
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++) {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        ind[y]++;
        outd[x]++;
    }
    for(int i=1;i<=n;i++) {//保证字典序最小(先搜索编号小的)
        sort(g[i].begin(),g[i].end());
    }
    int st=1;//所有点出度=入度，从一开始遍历
    int flag=1;//标记是否为回路,1为回路
    int c[2]={0,0};//c[0]入度比出度大1的点的个数 即终点的个数   c[1]出度比入度大1的点的个数 即起点的个数
    for(int i=1;i<=n;i++) {
        if (ind[i]!=outd[i]) {
            flag=0;//不是回路
            if (abs(ind[i]-outd[i])!=1) {
                printf("No\n");
                return 0;
            }
            if (outd[i]-ind[i]==1) {//起点
                c[1]++;
                st=i;
            }else {
                c[0]++;
            }
        }
    }
    if (flag==0&&(c[0]!=1||c[1]!=1)) {//起点或者终点不止一个 则不存在欧拉路径
        printf("No\n");
        return 0;
    }
    dfs(st);//有欧拉路径
    while(!ans.empty())
    {
        printf("%d ",ans.top());
        ans.pop();
    }
    printf("\n");
    return 0;
}

