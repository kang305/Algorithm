//https://www.luogu.com.cn/problem/P10387#ide
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;

struct node {
    int time;//次数
    int spend;//花费
}p[100009];
ll n,cost;
ll ans;
bool cmp(node &a, node &b) {
    return a.time<b.time;
}
int main(){
    cin>>n>>cost;
    ll total_cost=0;//计算剩下需要的总花费
    for (int i=1;i<=n;i++) {
        cin>>p[i].spend>>p[i].time;
        total_cost+=p[i].spend;
    }
    sort(p+1,p+n+1,cmp);//按照次数排序
    ll cnt=0;//组团训练的次数
    for (int i=1;i<=n;i++) {
        if (p[i].time<=cnt) {//i士兵次数小于
            total_cost-=p[i].spend;//直接训练完成，总费用减去该士兵的费用
            continue;
        }
        if (total_cost>=cost) {//总花费大于组队花费
            ans+=(p[i].time-cnt)*cost;//按照组队训练
            cnt+=p[i].time-cnt;//更新还需要的训练次数
        }else {//组队不划算了，单独训练
            ans+=p[i].spend*(p[i].time-cnt);//单独花费*剩余训练次数
        }
        total_cost-=p[i].spend;
    }
    cout<<ans<<endl;
    return 0;
}
