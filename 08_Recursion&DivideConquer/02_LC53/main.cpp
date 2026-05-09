#include<bits/stdc++.h>
using namespace std;
//分治解法
int max_mid(vector<int>& nums,int left,int mid,int right)
{
    //包括mid的往左延伸的最大值
    int left_ans=INT_MIN;
    int sum=0;
    for (int i=mid;i>=left;i--) {//从mid向左遍历到left
        sum+=nums[i];
        left_ans=max(left_ans,sum);
    }
    //（不包含）mid的往右延伸的最大值
    int right_ans=INT_MIN;
    sum=0;
    for(int i=mid+1;i<=right;i++)
    {
        sum+=nums[i];
        right_ans=max(right_ans,sum);
    }
    return left_ans+right_ans;
}
int max_ans(vector<int>& nums,int left,int right)
{//nums[l]~~nums[r] 最大子数组和
    if (left==right) {
        return nums[left];
    }
    int mid=(left+right)/2;//分为三段
    //[left,mid]最大数组和
    int ans1=max_ans(nums,left,mid);
    //[mid+1,right]
    int ans2=max_ans(nums,mid+1,right);
    //横跨mid
    int ans3=max_mid(nums,left,mid,right);
    return max(ans1,max(ans2,ans3));
}
int maxSubArray(vector<int>& nums)
{
    int ans=INT_MIN;
    int n=nums.size();
    ans=max_ans(nums,0,n-1);
    return ans;
}

//dp解法
int maxSubArray_dp(vector<int>& nums)
{
    int ans=INT_MIN;
    int n=nums.size();
    //定义dp[i]表示以nums[i]结尾的最大子数组和。
    vector<int>dp(nums.size());
    dp[0]=nums[0];
    //若可以nums[i]和前面的子数组拼起,也就是在以nums[i−1]结尾的最大子数组和之后添加nums[i],那么dp[i]=dp[i−1]+nums[i]。
    //dp[i]一定有nums[i]
    for(int i=1;i<n;i++) {
        dp[i]=max(dp[i-1],0)+nums[i];//第i个如果前面dp[i-1]最大值<0,则重新从nums[i]开始计数
    }
    for (int i=0;i<n;i++) {//找dp[i]中最大值
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main()
{
    int n,x;
    vector<int>nums;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        nums.push_back(x);
    }
    int ans=maxSubArray(nums);

    cout<<ans<<endl;
    return 0;
}