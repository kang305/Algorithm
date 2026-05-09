//https://www.luogu.com.cn/problem/P1460
#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef pair<string,int> pii;
int v, g;
int need[30];//需要的维生素
int feed[30][30];//各饲料对应的维生素
bool visited[1<<20];//每一种组合对应唯一一种数
int get_index(const string& s) {//计算该字符串对应的数
    int idx=0;
    for (int i=0;i<g;++i) {//将类似1010的组合转换为整数，作为该组合的编号
        idx=idx*2+(s[i]-'0');
    }
    return idx;
}

bool check(const string& s) {
    int total[30]={0};
    for (int i=0;i<g;++i) {//将当前组合，每种维生素进行统计
        if (s[i]=='1'){
            for (int j=0;j<v;++j) {//对下标i(1为投喂该饲料)，加入total数组
                total[j]+=feed[i][j];
            }
        }
    }
    for (int j=0;j<v;++j) {//该种组合不能满足需求
        if (total[j]<need[j])return 0;
    }
    return 1;
}

int main() {
    cin>>v;
    for(int i=0;i<v;++i) {
        cin>>need[i];
    }
    cin>>g;
    for(int i=0;i<g;++i) {
        for (int j=0;j<v;++j) {
            cin>>feed[i][j];
        }
    }
    string start(g, '0');//000队头入队
    int start_idx=get_index(start);
    visited[start_idx]=1;
    queue<pii>q;
    q.push({start, 0});

    while (!q.empty()) {
        string now=q.front().first;
        int last=q.front().second;//当前选中编号最大的数，只会更新后面的组合
        q.pop();
        if (check(now)) {//检查当前的组合是否满足
            //满足输出
            int ans[25];
            int ansSize=0;
            for (int i=0;i<g;++i) {
                if (now[i]=='1') {
                    ans[ansSize++]=i+1;//下标从1开始
                }
            }
            cout<<ansSize;
            for (int k=0;k<ansSize;++k)cout<<" "<<ans[k];
            cout<<endl;
            return 0;
        }
        for (int i=last+1;i<=g;++i) {//检查新的组合情况
            //一层一层进行入队，从种类1种到种类2以此类推
            string next=now;//存队头的组合，就可以固定前面的选择，对后面组合进行
            //100出队->110,101入队
            next[i-1]='1';
            int t_idx=get_index(next);
            if (!visited[t_idx]) {
                visited[t_idx]=1;//标记此时的组合
                q.push({next,i});
            }
        }
    }
    return 0;
}