#include<bits/stdc++.h>
using namespace std;
int arr1[50009];
int sum;
int n,m;
int check(int mid) {
    int cnt =0;//统计需要搬走的石块
    int now=0,next=0;
    while (next<n) {//next未到终点可以继续向后,不取等是因为终点不可以去除(默认将后一个去除)
        next++;
        if (mid<=arr1[next]-arr1[now]) {//两块石块的距离不能<暂时假设的最小值mid
            now=next;
        }else {
            cnt++;
        }
        if (cnt>m) {
            return cnt;
        }
    }
    return cnt;
}
int main(){
    cin>>sum>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>arr1[i];
    }
    arr1[n+1]=sum;//将终点加入数组
    n++;
    int left=1;
    int ans;
    int right=sum;//最大跨越距离是起点到终点
    while (left<=right) {
        int mid=(left+right)/2;//将中间值假设为答案(最小值)进行验证和调整
        if(check(mid)>m) {//移走的石块大于限制-->mid太大了,要移走更多的才可以保证每一次跳跃距离<mid
            right=mid-1;
        }else {           //移走的石块小于限制-->mid为答案或者可以更大,不移走石块或者移走更多石块
            left=mid+1;
            ans=mid;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*ans的含义:
 * 在移除<=m块石块的时候,剩余石块之间距离的最小值(其余的距离都要大于这个最小值),在所有最小值中的最大值
 */