//https://www.luogu.com.cn/problem/P8801
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
string s;
int len;
ll dp[20][105][105];//从第pos位开始，在剩余a次加法和b次减法的限制下，能够得到的最大数值
ll pow_10[20];//从高位开始贪心，低位计算的时候加上高位上10的幂

ll dfs(int pos, int a, int b) {
    if (pos==len)return 0;
    if (dp[pos][a][b]!=-1)return dp[pos][a][b];
    int d=s[pos]-'0';//pos位置的数
    ll res=-1;//pos位置最后的结果
    for (int t=9;t>=0;--t) {//遍历pos位置所以可能的结果进行贪心
        int add=(t-d+10)%10;//操作1需要的次数
        int sub=(d-t+10)%10;//操作2需要的次数
        ll best=-1;
        bool flag=false;//检查当前的t是否有效
        if (add<=a) {//操作1
            ll rest=dfs(pos+1,a-add,b);//剩下位的最大值
            best=max(best,t*pow_10[len-pos-1]+rest);//最高位*t+剩下的位的最大
            flag=true;
        }
        if (sub<=b) {//操作2
            ll rest=dfs(pos+1,a,b-sub);
            best=max(best,t*pow_10[len-pos-1]+rest);
            flag=true;
        }
        if (flag) {//t是从9开始减，当找到一个t，就是该位置的最大值
            res=best;
            break;
        }
    }
    return dp[pos][a][b]=res;
}

int main() {
    cin>>s;//用字符串存数
    len = s.size();
    int A,B;
    cin>>A>>B;
    pow_10[0] = 1;
    for (int i=1;i<=18;i++) {
        pow_10[i]=pow_10[i-1]*10;
    }
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,A,B)<<endl;
    return 0;
}