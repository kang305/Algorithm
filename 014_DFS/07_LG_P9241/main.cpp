#include <iostream>
#include<algorithm>
using namespace std;
int n,vis[12];
struct plane {
    int t,d,l;
}p[12];
bool dfs(int x,int sum) {//第x架飞机，上一架飞机降落时间
    if (x>n) {
        return 1;
    }
    for(int i=1;i<=n;i++) {
        if (vis[i]||p[i].t+p[i].d<sum)continue;//已经降落或不够时间
        vis[i]=1;
        if (dfs(x+1,max(sum,p[i].t)+p[i].l)) {//要到达后或前一架降落才可以考虑当前的降落
            //sum>到达时间,前面的判断已经考虑了盘旋时间是否足够,盘旋时间>sum-p[i].t
            //sum<=到达时间，到达后就可降落
            vis[i]=0;
            return 1;
        }
        vis[i]=0;
    }
    return 0;
}
int main()
{
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>p[i].t>>p[i].d>>p[i].l;
        }
        memset(vis,0,sizeof(vis));
        if(dfs(1,0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}