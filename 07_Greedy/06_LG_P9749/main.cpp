//https://www.luogu.com.cn/problem/P9749
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
int main() {
    int n,d;
    cin>>n>>d;
    int dist[100009];
    int oill[100009];
    for(int i=1;i<n;i++) {
        cin>>dist[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>oill[i];
    }
    ll total_cost=0;//总花费
    int Min_cost=INT_MAX;//当前最小加油位置
    ll last_dist=0;//上次加油后剩余可行驶路程
    int need_oill=0;//需要的燃油
    for(int i=1;i<n;i++) {
        if(oill[i]<Min_cost) {//有更小的更新选择(未更新代表至少加到下次可以更新花费的站点)
            Min_cost=oill[i];
        }
        last_dist+=dist[i];//到下一个站点还需要行驶到路程
        if (last_dist>0) {
            need_oill=(last_dist+d-1)/d;//向上取整,到下一个站点需要的油
            total_cost+=need_oill*Min_cost;
            last_dist=last_dist-(need_oill*d);//更新剩余路程(向上取整可为负数)
        }
    }
    cout<<total_cost<<endl;
    return 0;
}