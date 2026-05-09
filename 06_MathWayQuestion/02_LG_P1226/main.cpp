/*https://www.luogu.com.cn/problem/P1226*/
#include<bits/stdc++.h>
using namespace std;
long long a,b,p,x,n;
long long res=1;
int main(){
    //数据太大,需要在计算过程中就进行取模
    cin>>a>>b>>p;
    x=a;//a和b输出时还要使用,用临时变量x,p分别保存
    n=b;
    while(n!=0) {
        if (n%2==1) {
            res=(res*x)%p;
        }
        n/=2;
        x=(x*x)%p;
    }
    res=res%p;
    printf("%lld^%lld mod %lld=%lld",a,b,p,res);
    return 0;
}