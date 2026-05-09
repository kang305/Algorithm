/*https://www.luogu.com.cn/problem/P1824*/
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n,m;
int check(int mid) {
    int cnt=1;//第一个位置放牛,最大化利用空间
    int now=0,next=1;
    while(next<n) {
        if (a[next]-a[now]>=mid) {//两个栏中间的距离>mid最小距离-->需要放奶牛
            cnt++;
            now=next;
        }
        next++;//距离不够next继续向后扩大距离
        if(cnt>m) {//提前退出优化
            break;
        }
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0;
    int left=1;
    int right=a[n-1]-a[0];//最长距离是排序后第一和最后中间的距离
    while(left<=right) {
        int mid=(left+right)/2;//最短距离(其他间隔必须>mid)
        if(check(mid)>=m) {//mid条件下奶牛数>=限制-->mid偏小,增加mid使奶牛数量减少(也满足找最大)
            left=mid+1;
            ans=mid;
        }else {
            right=mid-1;//mid偏大,要减少最短距离
        }
    }
    cout<<ans<<endl;
    return 0;
}
