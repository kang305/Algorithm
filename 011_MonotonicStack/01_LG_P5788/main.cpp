#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int n;//n<=100
int a[3000005];
stack<int>s;//a[i]
int ans[3000005];//ans[i]就是a[i]右边第一个比a[i]大的数
//从左向右找第一个更大的元素-->从右向左遍历,单调递减栈
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=n;i>=1;i--) {
        while(!s.empty() && a[s.top()]<=a[i]) {//栈顶元素小于当前判断元素,开始出栈,直到栈顶元素大于当前判断
            s.pop();
        }
        if(s.empty()) {//栈空,当前元素没答案
            ans[i]=0;
        }else {        //当前元素>栈顶元素-->当前元素就是栈顶元素的答案
            ans[i]=s.top();
        }
        s.push(i);
    }

    for(int i=n;i>=1;i--)
    {

        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }

        return 0;
    }
}