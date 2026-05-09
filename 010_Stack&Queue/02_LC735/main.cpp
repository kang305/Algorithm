/*https://leetcode.cn/problems/asteroid-collision/description/*/
#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids)
{
    int n=asteroids.size();
    vector<int> ans;//利用数组模拟栈
    for(int i=0;i<n;i++) {
        if (ans.empty()||asteroids[i]>0) {//1.++ 2.-+  -->即要加入的元素是+
            ans.push_back(asteroids[i]);
        }else {//这里的asteroids[i]<0
            //栈顶为+,要入栈的为-且栈顶元素小要被撞没且可能会连续相撞用while
            while (ans.size()&&ans.back()>0&&ans.back()<-asteroids[i]) {
                ans.pop_back();
            }
            if (ans.size()==0||ans.back()<0) {//- -不撞
                ans.push_back(asteroids[i]);
            }
            else if (ans.back()==-asteroids[i]) {//两个都撞没
                ans.pop_back();
            }
        }
    }
    return ans;
}
int main()
{
    int n,x;
    vector<int>a;
    vector<int>ans;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    ans=asteroidCollision(a);
    int l=ans.size();
    for(int i=0;i<l;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
/*
 * ++不撞
 * -+不撞
 * --不撞
 * +-撞
 */