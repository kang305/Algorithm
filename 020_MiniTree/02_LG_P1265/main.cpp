//https://www.luogu.com.cn/problem/P1265
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
#define INF 1e9
struct point {
    double x,y;
}p[50005];
double dist[5005],ans=0.00;
int v[5005];
double dis(point p1,point p2) {//距离公式
    return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(double)(p1.y-p2.y)*(p1.y-p2.y));
}
int main(){
    cin>>n;
    int x,y;

    for(int i=1;i<=n;i++) {
        cin>>x>>y;
        p[i].x=x;
        p[i].y=y;
    }
    dist[1]=0;
    v[1]=1;
    //要找离i点最近的点，相当于要创建一个全向图
    for(int i=2;i<=n;i++) {
        dist[i]=dis(p[1],p[i]);
    }
    double mini=INF;
    int index=0;
    for(int i=1;i<n;i++) {
        mini=INF;
        index=-1;
        for(int j=1;j<=n;j++) {
            if(dist[j]<mini&&v[j]==0) {
                mini=dist[j];
                index=j;
            }
        }
        v[index]=1;
        ans+=mini;
        for(int k=1;k<=n;k++) {
            if (v[k]==0&&dist[k]>dis(p[index], p[k])) {//可以找到距离index更加小的点
                dist[k]=dis(p[index], p[k]);
            }
        }

    }
    printf("%.2lf",ans);
    return 0;
}