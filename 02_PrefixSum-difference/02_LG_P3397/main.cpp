/*https://www.luogu.com.cn/problem/P3397#ide*/
#include<bits/stdc++.h>
using namespace std;
int b[10005][10005];
int a[10005][10005];
int n,m;
int main() {
    cin >> n >> m;
    int lx,ly,rx,ry;
    while (m--) {
        cin >> lx >> ly >> rx >> ry;
        b[lx][ly]++;
        b[lx][ry+1]--;
        b[rx+1][ly]--;
        b[rx+1][ry+1]++;
    }
    a[1][1] = b[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]+b[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
