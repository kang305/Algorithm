#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        b.push_back(k); //将k放在末尾
        int ans = INT_MIN;
        int m = n + 1;
        for (int i = 0; i < m; i++) {//[0,n]
            int sum = b[i] + b[(i + 1) % m];//前面找后一个匹配,最后找第一个
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
    return 0;
}