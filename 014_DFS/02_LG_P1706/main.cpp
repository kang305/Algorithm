/*https://www.luogu.com.cn/problem/P1706*/
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int ans[19];
int flag[19];
void print() {
    for (int i = 1; i <= n; i++) {
        printf("%5d", ans[i]);
    }
    printf("\n");
}
void dfs(int x) {//判断第x个位置填什么数--给第x个位置填数字
    if (x>n) {//第n个数填满了，输出一个答案
        print();
        return;
    }
    for (int i = 1; i <= n; i++) {//枚举所有可以填的数
        if (flag[i]==0) {
            ans[x] = i;//把i填到x位置
            flag[i] = 1;
            dfs(x+1);//继续填下一个位置
            flag[i]=0;//继续考虑其他选择，把i变成其他位置可用的状态-->在回溯时撤销本层所做过的事情
        }
    }

}
int main(){
    ios:: sync_with_stdio(0);
    cin. tie (0);
    cin >> n;
    dfs(1);//从第一个位置开始，去找每个位置填什么数字
}