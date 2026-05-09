/*https://www.luogu.com.cn/problem/P1182*/
#include<bits/stdc++.h>
using namespace std;
int a[500009];
int n,m;
int check(int mid) {//记录分割次数,段数=cnt+1
    int cnt = 0;//计数
    int flag=0;//计算总和
    for (int i=1;i<=n;i++) {
        if (flag+a[i]<=mid) {//flag+a[i]<=mid如果<mid(假设的最大值),把a[i]加入总和
            flag+=a[i];
        }else {//比最大值大了,重新开一个区间,计数++
            cnt++;
            flag=a[i];
        }
    }
    return cnt;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int sum=0;
    int left=0;
    for(int i=1;i<=n;i++) {
        sum+=a[i];
        left=max(left,a[i]);//left不一定取1或0,而是取范围的最小值
        //这里取了存储数组的最大值:任何分段方案的最大段和不可能小于数组中的最大元素
    }

    int right=sum;//最大情况就是全部相加
    int ans=0;//记录答案
    while(left<=right) {
        int mid=(left+right)/2;
        if(check(mid)<m) {//分的区间比限定区间数少:mid大了,一组需要更多才能满足mid
            ans=mid;//切割次数<m-->段数<=m所有满足情况
            right=mid-1;
        }else {     //段数>m,需要把mid扩大,让更多的元素可以在同一组,减少段数
            left=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}