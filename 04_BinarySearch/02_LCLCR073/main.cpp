/*https://leetcode.cn/problems/nZZqjQ/description/*/
#include<bits/stdc++.h>
using namespace std;
vector<int>piles;
int n,h;
int minEatingSpeed(vector<int>& piles, int h) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); //加速
    int Max=0;
    int left=1;
    int n=piles.size();
    int ans=0;
    for(int i=0;i<n;i++){
        Max=max(Max,piles[i]);
    }
    long long tmp;
    int right=Max;
    int mid;
    while(left<=right) {
        int mid = left + (right - left) / 2;
        tmp=0;
        for(int i=0;i<n;i++) {
            tmp += (piles[i] + mid - 1) / mid;//向上取整
            if(tmp > h) break;
            /*等价写法
           if (piles[i]%mid==0) {
               tmp+=piles[i]%mid;
           }else {
               tmp=tmp+piles[i]%mid+1;
           }
           if(tmp > h) break;
            */
        }
        if(tmp>h) {
            left=mid+1;
        }else {
            right=mid-1;
            ans=mid;
        }
    }
    return ans;
}

int main() {
    vector<int>piles;
    int n,h;
    cin>>n>>h;
   for(int i=0;i<n;i++) {
       int x;
       cin>>x;
       piles.push_back(x);
   }
    int ans=minEatingSpeed(piles,h);
    cout<<ans<<endl;
}