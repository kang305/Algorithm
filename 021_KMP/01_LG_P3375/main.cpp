//https://www.luogu.com.cn/problem/P3375
#include <iostream>
#include <string>
using namespace std;
char str[1000006];
char sub[1000006];
int Next[1000006];
int main() {
    scanf("%s", str);
    getchar();
    scanf("%s", sub);
    int len = strlen(sub);//模式串长度
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
    int len2=strlen(str);//主串长度
    int i=0;
    j=0;
    while(i<len2) {//主串没走到最后不可以停
        if(j==-1||str[i]==sub[j]) {
            i++;
            j++;
        }else {
            j=Next[j];
        }
        //匹配完一次
        if (j==len) {
            cout<<i-len+1<<endl;//从0开始存，输出要加1
            j=Next[len];//匹配完一个，开始检查后面，当作最后位置匹配失败，继续检查剩下的
        }
    }
    for (int i=1;i<=len;i++) {
        cout<<Next[i]<<' ';
    }
    return 0;
}