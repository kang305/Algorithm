//https://www.luogu.com.cn/problem/P4391
#include <iostream>
#include <string>
using namespace std;
char sub[1000006];
int Next[1000006];
int main() {
    int n;
    cin>>n;
    scanf("%s",sub);
    int len=strlen(sub);
    Next[0]=-1;
    Next[1]=0;
    int k=0,j=1;
    while(j+1<=len) {
        if (k==-1||sub[k]==sub[j]) {
            Next[j+1]=k+1;
            k++;
            j++;
        }else {
            k=Next[k];
        }
    }
    printf("%d\n", len-Next[len]);//最短循环子串=模式串长度-模式串最长相等前后缀(Next[len])
    return 0;
}