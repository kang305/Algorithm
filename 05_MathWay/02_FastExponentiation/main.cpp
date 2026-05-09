#include<iostream>
#include<string>
using namespace std;
int FastExponentiation(int n, int x) {//n的x次幂
    int res = 1;
    while (x) {
        if (x%2 == 1) {
            res=res*n;
        }
        x/=2;
        n=n*n;
    }
    return res;
}
int m_fun(int n,int x) {
    int res=1;
    while (x!=0) {
        if (x%2==1) {
            res=res*n;
        }
        x/=2;
        n*=n;
    }
    return res;
}
int main()
{
int n,x;
cin>>n>>x;
    cout << FastExponentiation(n,x) << endl;
    return 0;
}