#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int n,m,ans;
int a[100006];
ll l,r;
bool check(ll mid) {
    int cnt=0;//计数
    for (int i=1;i<=n;i++) {
        int dist=a[i]-a[i-1];
        if (dist<=mid)continue;//距离小于L,可以直接跳到，不需要加检查点
        //需要加检查点
        cnt+=(dist+mid-1)/mid-1;//向上取整(点数=段数-1)
        if (cnt>m)return 0;//超过可以加的点数，改L太小
    }
    return 1;
}
int main(){
    cin>>n>>m;
    m++;//用技能的时候可以看作需要多经过一个检查点
    a[0]=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    l=1;
    r=a[n];//能取到最大值
    while (l<=r) {
        ll mid=(l+r)/2;
        if (check(mid)) {//mid=L可以满足题意，检查更小的L
            ans=mid;
            r=mid-1;
        }else {
            l=mid+1;//扩大L
        }
    }
    cout<<ans<<endl;
    return 0;
}