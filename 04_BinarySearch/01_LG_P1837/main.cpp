/*https://www.luogu.com.cn/problem/P1873*/
#include<iostream>
using namespace std;
int n,m;
int tree[1000008];
bool check(int mid) {
    long long tmp=0;
    for(int i=0;i<n;i++) {
        if(tree[i]>mid) {
            tmp+=(tree[i]-mid);
        }
    }
    if(tmp>=m) {
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int Max=0;
    int ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>tree[i];
        Max=max(Max,tree[i]);
    }

    int mid=0;
    int left=0,right=Max;
    while(left<=right) {
        mid=(left+right)/2;
        if(check(mid)==true) {
            ans=mid;
            left=mid+1;
        }else {
            right=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
