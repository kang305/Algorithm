/*https://www.luogu.com.cn/problem/P4387*/
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[100001];//存储入栈顺序
int b[100001];//存储出栈顺序
int in,out;//栈指针
stack<int> s;
int main()
{
    cin>>n;
    while(n--) {
        cin>>m;
        //先将上一组的数据清空
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        while(!s.empty()) {
            s.pop();
        }
        for (int i=0;i<m;i++) {
            cin>>a[i];
        }
        for (int i=0;i<m;i++) {
            cin>>b[i];
        }
        in=0;
        out=0;
        for (in=0;in<m;in++) {
            s.push(a[in]);//第i个数入栈
            while (!s.empty()&&s.top()==b[out]) {//栈顶与输出相同可以出栈
                s.pop();
                out++;
            }
        }
        if (s.empty()) {//如果栈可以输出完,就是合法输出结果
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}