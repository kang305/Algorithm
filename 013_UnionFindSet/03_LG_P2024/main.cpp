/*https://www.luogu.com.cn/problem/P2024*/
//A->B->C->A,一个循环食物链
#include <iostream>
#include<algorithm>
using namespace std;
struct animal {
    int num,a,b;
}a[100005];
int f[150004];//三倍，猎物是i+n,天敌是i+2*n
int find(int x) {//寻找根节点
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}

int main() {
    int n,K;
    cin>>n>>K;
    int cnt=0;
    for (int i=1;i<=3*n;i++) {
        f[i]=i;
    }
    for (int i=1;i<=K;i++) {
        cin>>a[i].num>>a[i].a>>a[i].b;
        int operation=a[i].num;//记录操作
        int x=a[i].a;
        int y=a[i].b;
        if(x>n||y>n) {//大于总数
            cnt++;
            continue;
        }
        if (x==y&&operation==2) {//x吃自己或同类
            cnt++;
            continue;
        }
        int fa,fb,fa_f,fb_f,fa_e,fb_e;
        fa=find(x);//x自己或同类的根节点
        fb=find(y);//y自己或同类的根节点
        fa_f=find(x+n);//x的食物，放在i+n
        fb_f=find(y+n);//y的食物，放在i+n
        fa_e=find(x+2*n);//x的天敌，放在i+2*n
        fb_e=find(y+2*n);//x的天敌，放在i+2*n
        if (operation==1) {//x和y是同类
            if (fa==fb_e||fb==fa_e) {//假话:x被y吃或y被x吃
                cnt++;
            }else {//更新并查集
                f[fa]=fb;//将x和y加入同一个集合
                //x和y的食物天敌相同
                f[fa_e]=fb_e;
                f[fa_f]=fb_f;
            }
        }else {//x吃y
            if (fa==fb||fa==fb_f) {//假话：x和y同类，x被y吃
                cnt++;
            }
            else {//更新并查集，以下由循环食物链得
                f[fa_f]=fb;//y是x的食物
                f[fa_e]=fb_f;//x的天敌是y的食物
                f[fa]=fb_e;//x是y的天敌
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}