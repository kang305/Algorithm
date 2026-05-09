#include<iostream>
#include<vector>
using namespace std;
int n, k, ans1 = 0;
int a[29];
int vis[29]; //标记数组，防止递归的时候重复访问
int tmp[30];//临时存一种组合情况
vector<int>ans;
void add() {//将临时组合的情况相加，放入结果数组
    int sum = 0;
    for (int i=1;i<=k;i++) {
        sum+=tmp[i];
    }
    ans.push_back(sum);
}

void dfs(int x,int now) {//组合
    if (x>k) {//当下标超过k
        add();
        return;
    }
    for (int i=now;i<=n;i++) {//now是当前的下标，保证不会当前元素不会和前面元素结合，防止重复
        if (!vis[i]) {//该顶点未被访问
            vis[i]=1;
            tmp[x]=a[i];
            dfs(x+1, i+1);
            vis[i]=0;//回溯清除操作
        }
    }
}
bool isPrime_nomal(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    cin >> n >> k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    dfs(1, 1);
    for (int i = 0; i < ans.size(); i++) {
        if (isPrime_nomal(ans[i])) {
            ans1++;
        }
    }
    cout << ans1 << endl;
    return 0;
}