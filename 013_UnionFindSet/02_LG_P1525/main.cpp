/*https://www.luogu.com.cn/problem/P1525*/
//我们依次尝试分开每一对冲突，从大到小，直到遇到第一对无法分开的，它就是最终答案；
//如果全部都能分开，答案就是0，最小化最大值
#include <iostream>
#include<algorithm>
using namespace std;
int father[40005];
int N,M;
struct crime {
    int a,b,c;
}c[100005];
int find(int x) {//查找函数含路径压缩
    if(x == father[x]) {
        return x;
    }
    else {
        return father[x]=find(father[x]);
    }
}
bool cmp(crime &a,crime &b) {//sort的功能函数，使得c数组可以降序排
    return (a.c) > (b.c);//贪心：先处理最大的冲突
}
int main() {
    cin >> N >> M;
    int fa,fb,fa_d,fb_d;
    for(int i=1;i<=N*2;i++) {//进行并查集初始化
        father[i]=i;
    }
    for(int i=1;i<=M;i++) {
        cin>>c[i].a>>c[i].b>>c[i].c;
    }
    sort(c+1,c+M+1,cmp);
    for(int i=1;i<=M;i++) {
        fa=find(c[i].a);//a罪犯所在的集合
        fb=find(c[i].b);//b罪犯所在的集合
        fa_d=find(c[i].a+N);//a罪犯敌人所在的集合
        fb_d=find(c[i].b+N);//b罪犯敌人所在的集合
        if (fa==fb) {//代表此时a和b已经在同一所监狱，不可分开(敌人的敌人是朋友)
            cout<<c[i].c<<endl;
            return 0;
        }
        //否则
        father[fa]=fb_d;//将b的敌人加入a的集合
        father[fb]=fa_d;//将a的敌人加入ab的集合
    }
    //如果成功处理完所有冲突，说明可以完全避免冲突，答案为0
    cout<<0<<endl;
    return 0;
}