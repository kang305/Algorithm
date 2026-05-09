/*https://www.luogu.com.cn/problem/P3853#ide*/
#include<bits/stdc++.h>
using namespace std;
int a[100008];
int l,n,m;
int check(int mid) {//统计在最大间隔距离为mid时需要加入多少个石块
    int cnt=0;
    for(int i=2;i<=n;i++) {
        if (a[i]-a[i-1]>mid) {//两块石块中间距离>mid,
            if ((a[i]-a[i-1])%mid==0) {//能够整除,d/mid-1(可以分为n块,需要n-1块石块)
                cnt+=(a[i]-a[i-1])/mid-1;
            }else {                    //不能够整除,d/mid不需要改变(多出来的部分也需要石块)
                cnt+=(a[i]-a[i-1])/mid;
            }
        }
        if (cnt>m) {//优化检查次数
            break;
        }
    }
    return cnt;
}
int main(){
    cin>>l>>n>>m;
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    int left=1,right=l;//left为最小间隔,right为最大间隔
    int ans=0;
    while (left<=right) {
        int mid=(left+right)/2;//以mid为假设最大间隔,进行检查
        if (check(mid)<=m) {//需要的石块比限制小,mid就是答案或者最大间隔mid太大
            ans=mid;
            right=mid-1;
        }else {
            left=mid+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
