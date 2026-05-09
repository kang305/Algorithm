//https://www.luogu.com.cn/problem/P1194
#include<iostream>
#include<algorithm>
using namespace std;
int a,b;
int father[505];
struct edge {
    int u,v,w;
}e[350009];
bool cmp(const edge &x,const edge &y)
{
    return x.w<y.w;
}
int find(int x)//查找根节点，并进行路径压缩
{
    if(x!=father[x])return father[x]=find(father[x]);
    return father[x];
}
int cnt=0;
int main(){
cin>>a>>b;
    //引入虚假物品价格为0.先买它再买其他，其他物品为a,0-a->i
    for (int i=1;i<=b;i++) {//买东西为a元，即虚假物品到每一个物品到价格都是a
        ++cnt;
        e[cnt].u=0;
        e[cnt].v=i;
        e[cnt].w=a;
    }
    int k;
    for (int i=1;i<=b;i++) {
        for (int j=1;j<=b;j++) {//邻接矩阵
            cin>>k;
            if (k!=0) {//k=0是对角线
                ++cnt;
                e[cnt].u=i;
                e[cnt].v=j;
                e[cnt].w=k;
            }
        }
    }
    sort(e+1,e+(cnt+1),cmp);//先对边集数组进行排序
    for (int i=0;i<=b;i++) {//并查集初始化
        father[i]=i;
    }
    int x,y,fx,fy,sum=0;
    for (int i=1;i<=cnt;i++) {//kruskal
        x=e[i].u;
        y=e[i].v;
        fx=find(x);
        fy=find(y);
        if (fx!=fy) {
            sum+=e[i].w;
            father[fy]=fx;
        }
    }
    cout<<sum<<endl;
    return 0;
}
