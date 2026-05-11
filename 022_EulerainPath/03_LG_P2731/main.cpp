#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
int m;
int graph[506][509];//邻接矩阵方便进行排序，找最小字典序
int d[509];//统计度
stack<int> ans;//存储结果的点，并输出
int st;
int Max=-1,Min=509;//下标最大最小的值

int del[509]; //扫描指针,需在main中初始化为Min
void dfs(int x) {//弧优化
    while (del[x] <= Max) {
        int i=del[x];
        if (graph[x][i]>0) {       //这个边可以走
            graph[x][i]--;
            graph[i][x]--;
            dfs(i);                  //走到邻居 i
            //注意：del[x]不变,继续在i上检查是否还有重边
        } else {
            del[x]++;                //当前邻居无边，指针后移
        }
    }
    ans.push(x);                     //所有边处理完毕，压栈
}

void dfs_normal(int x) {//无弧优化
    for (int i=Min;i<=Max;i++) {
        if (graph[x][i]>0) {
            graph[x][i]--;
            graph[i][x]--;
            dfs(i);
        }
    }
    ans.push(x);
}

int main() {
    cin>>m;
    int x,y;
    for(int i=1;i<=m;i++) {
        cin>>x>>y;
        //找编号最大最小的点
        Min=min(Min,min(x,y));
        Max=max(Max,max(x,y));
        //模拟邻接矩阵存图(要存重复边，所有不止0或1)
        graph[x][y]++;
        graph[y][x]++;
        d[x]++;d[y]++;
    }
    st=Min;//起点标记为最小的点
    for (int i=Min;i<=Max;i++) {//从小往大遍历，先找到的一定是最小的点
        if(d[i]%2==1) {//无向图只有起点或终点的度可能为奇数
            st=i;
            break;
        }
    }
    dfs(st);
    while(!ans.empty())
    {
        printf("%d\n",ans.top());
        ans.pop();
    }

    return 0;
}

/*1.所有栅栏都是连通的(也就是你可以从任意一个栅栏到达另外的所有栅栏)--->连通的无向图
 *2.John能从任何一个顶点(即两个栅栏的交点)开始骑马，在任意一个顶点结束。--->找欧拉路径，即不保证是回路，要找起点。如果是回路，用最小编号做起点。
 *3.输入数据保证至少有一个解。---->题目保证是半欧拉图，不需要判断。
 *4.五百进制表示法---->字典序最小输出。 5.数据范围不大，直接邻接矩阵存图。跑Hierholzer 算法。*/
