#include<iostream>
using namespace std;
char str[105];
char sub[105];
int Next[105];
void getNext(char Sub[],int Next[],int lenSub) {
    Next[0]=-1;
    Next[1]=0;
    int j=1,k=0;//j定位模式串next值，k来确定next值
    while(j+1<=lenSub) {
        if (k==-1||Sub[k]==Sub[j]) {
            Next[j+1]=k+1;
            k++,j++;
        }else {
            k=Next[k];
        }
    }

}
int KMP(char Str[],char Sub[]) {
    int ls=strlen(Sub);//模式串长度
    int lp=strlen(Str);//目标串长度
    int i=0,j=0;//目标串索引，模式串索引
    getNext(Sub,Next,ls);
    while (i<lp&&j<ls) {
        if (j==-1||Str[i]==Sub[j]) {
            i++,j++;
        }else {
            j=Next[j];
        }
    }
    if (j>=ls) {
        return i-ls;
    }
    return -1;
}

//求最短相同前后缀
int MinSub(char Sub[],int Next[],int lenSub) {
    Next[0]=-1;
    Next[1]=0;
    int j=1,k=0;//j定位模式串next值，k来确定next值
    while(j+1<=lenSub) {
        if (k==-1||Sub[k]==Sub[j]) {
            Next[j+1]=k+1;
            k++,j++;
        }else {
            k=Next[k];
        }
    }

    int n=lenSub;
    int x=n;
    if (Next[n]==0) {
        return 0;
    }else {
        while (Next[x]!=0&&Next[x]!=-1) {
            x=Next[x];
        }
    }
    return x;
}
int main() {
    scanf("%s",str);
    getchar();//去除换行
    scanf("%s",sub);
    int ans=KMP(str,sub);
    printf("%d\n",ans);
    return 0;
}