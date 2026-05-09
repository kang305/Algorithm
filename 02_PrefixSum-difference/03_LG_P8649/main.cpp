//https://www.luogu.com.cn/problem/P8649#ide
//不用滑动窗口：数据不单调
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cnt=0;//总数会爆int
int n,k;
int a;
ll sum[100009];//前缀和数组
ll b[100009];//存对k取模后，余数相同的前缀和(之间的子区间一定可以被整除)
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a;
        sum[i]=sum[i-1]+a;
    }
    for (int i=0;i<=n;i++) {//能够整除的前缀和存在0下标
        //余数相同在该余数下标位置加上该前缀和
        cnt+=b[sum[i]%k];//cnt加上该位置(当前找到的和以前找到的构成的子区间)
        b[sum[i]%k]++;//再将新找到的加入该位置
    }
    cout<<cnt;
    return 0;
}