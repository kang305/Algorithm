/*https://leetcode.cn/problems/trapping-rain-water/description/*/
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int trap(vector<int>& height){
    int sum=0;
    int n=height.size();
    stack<int>s;
    int h;//高度
    int w;//宽度
    for(int i=0;i<n;i++) {
        while (!s.empty()&&height[s.top()]<height[i]) {//栈顶小于下一个(可能存在凹槽)
            int m=s.top();//保存当前栈顶(凹槽底部)
            s.pop();
            if(!s.empty()) {//如果出栈后非空,代表形成了凹槽（单调递减栈）
                h=min(height[i],height[s.top()])-height[m];//两侧最短边-底部
                w=i-s.top()-1;
                sum+=h*w;
            }
        }
        s.push(i);
    }
    return sum;
}

int main()
{
    int n,x;
    vector<int>h;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        h.push_back(x);
    }
    int ans=trap(h);
    cout<<ans<<endl;
    return 0;
}