#include<iostream>
using namespace std;
int n;
int ans[14];
int check[3][28]={0};//检查列，副对角线，主对角线
int sum=0;
void print() {//输出
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
}
void dfs(int x) {
    if (x>n) {//当前行数>n,总和+1
        sum++;
        if (sum<=3){//超过3退出dfs(n+1)不会影响统计
            print();
        }
        return;
    }
    for (int i=1;i<=n;i++) {
        //不同的(x,i),对应的主副对角线是唯一的，所以可以直接用check一个位置表示这一整条
        if (check[0][i]==0&&check[1][x+i]==0&&check[2][x-i+n]==0) {//(x,i)主对角线x-i+n相同，副对角线x+i相同
            ans[x]=i;//将第(x,i)填入ans
            check[0][i]=1;
            check[1][x+i]=1;
            check[2][x-i+n]=1;
            dfs(x+1);
            //撤销上一层递归的操作,让错误的操作会在上一层递归结束后清除
            check[0][i]=0;
            check[1][x+i]=0;
            check[2][x-i+n]=0;
        }
    }
}
int main() {
    cin>>n;
    dfs(1);
    cout<<sum<<endl;
    return 0;
}