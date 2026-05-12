//https://www.luogu.com.cn/problem/P3370#ide
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int n,ans;//遍历的检查指针，答案
//自然溢出法：
typedef unsigned long long ull;
ull b=131;
ull h1[10005];
ull Hash1(char s[]) {
    int len = strlen(s);
    ull sum=(ull)s[0];//字符转化为ASCII
    for(int i=0;i<len;i++) {
        sum=sum*b+(ull)s[i];//自然溢出可以不模
    }
    return sum;
}
void solve1() {
    cin>>n;
    char s[1505];
    for(int i=1;i<=n;i++) {
        cin>>s;
        h1[i]=Hash1(s);
    }
    sort(h1+1,h1+n+1);
    ans=1;
    for(int i=2;i<=n;i++) {
        if(h1[i]!=h1[i-1])ans++;
    }
    cout<<ans<<endl;
}

//双哈希：
ull b1=131,b2=101;
ull m1=19260817,m2=19660813;
struct hash2{//存双哈希结果的结构体数组
    ull x,y;
}h2[10005];
bool cmp(const hash2 &a,const hash2 &b) {//对哈希结果进行排序的功能函数
    if(a.x==b.x)//x相等按照y从小到大排序
    {
        return a.y<b.y;
    }
    return a.x<b.x; //先按照x的升序排
}

ull Hash2(char s[],ull base,ull MOD) {//记得模MOD
    int len = strlen(s);
    ull sum=(ull)s[0];//字符转化为ASCII
    for(int i=0;i<len;i++) {
        sum=((sum*base)%MOD+(ull)s[i])%MOD;
    }
    return sum%MOD;
}
void solve2() {
    int n;
    cin>>n;
    char s[1505];
    for(int i=1;i<=n;i++) {
        cin>>s;
        //进行两次哈希
        h2[i].x=Hash2(s,b1,m1);
        h2[i].y=Hash2(s,b2,m2);
    }
    sort(h2+1,h2+n+1,cmp);
    ans=1;
    for(int i=2;i<=n;i++) {
        if(h2[i].x!=h2[i-1].x||h2[i].y!=h2[i-1].y)ans++;//只要有一个哈希值不同就是不同字符串，ans++
    }
    cout<<ans<<endl;

}
int main() {
    solve2();
    return 0;
}