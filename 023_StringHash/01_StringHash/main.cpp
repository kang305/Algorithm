#include<iostream>
#include<string>
using namespace std;
typedef unsigned long long ull;
//双哈希
struct hash2{//存双哈希结果的结构体数组
    ull x,y;
}h2[10005];
ull Hash2(char s[],ull base,ull MOD) {//记得模MOD
    int len = strlen(s);
    ull sum=(ull)s[0];//字符转化为ASCII
    for(int i=0;i<len;i++) {
        sum=((sum*base)%MOD+(ull)s[i])%MOD;
    }
    return sum%MOD;
}

//自然溢出
ull base;//按照题目要求取值
ull Hash1(char s[]) {
    int len = strlen(s);
    ull sum=(ull)s[0];//字符转化为ASCII
    for(int i=0;i<len;i++) {
        sum=sum*base+(ull)s[i];//自然溢出可以不模
    }
    return sum;
}

int main() {

    return 0;
}