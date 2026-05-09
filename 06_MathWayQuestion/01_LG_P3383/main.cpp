/*https://www.luogu.com.cn/problem/P3383*/
#include<bits/stdc++.h>
using namespace std;
bool isPrime[100000008];
int p[1000006];
int a[1000006];
int n,q;
void solve(int n) {
    int sum=0;
    isPrime[1] = 1;
    // 从2开始枚举所有数
    for (int i = 2; i <= n; i++) {
        // 如果i是质数（未被标记为合数）
        if (isPrime[i] == 0) {
            sum++;            // 质数计数器增加
            p[sum] = i;       // 将质数i存入数组p
        }
        // 核心筛法部分：用当前数i乘以所有已找到的质数
        for (int j = 1; j <= sum; j++) {
            int tmp = p[j] * i;  // 产生合数p[j]*i

            // 如果合数超出范围，终止内层循环
            if (tmp > n) break;

            // 标记该合数为非质数
            isPrime[tmp] = 1;
            // 保证每个合数只被其最小质因子筛掉一次
            if (i % p[j] == 0) break;//核心代码
        }
    }
}
int main(){
    cin >> n >> q;
    solve(n);
    for(int i=1;i<=q;i++) {
        scanf("%d",&a[i]);
        printf("%d\n",p[a[i]]);
    }

    return 0;
}
