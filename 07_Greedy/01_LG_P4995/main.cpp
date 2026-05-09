/*https://www.luogu.com.cn/problem/P4995#ide*/
#include<bits/stdc++.h>
using namespace std;
int a[400];
int n;
long long ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    a[0]=0;//开始是在地面
    sort(a,a+n+1);//从低到高排序
    int left=0;
    int right=n;
    while(left<right) {//从最低到最高,在到次低,重复此操作
        ans+=(a[right]-a[left])*(a[right]-a[left]);
        left++;
        ans+=(a[right]-a[left])*(a[right]-a[left]);
        right--;
    }
    cout<<ans<<endl;
    return 0;
}