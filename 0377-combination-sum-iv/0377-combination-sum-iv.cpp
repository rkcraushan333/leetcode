class Solution {
public:
    int f(vector<int>&v,int target,vector<vector<int>>&dp,int i=0)
    {
        if(target==0) return 1;
        if(target<0||i==v.size()) return 0;
        int &t = dp[i][target];
        if(t!=-1) return t;
        int ans = 0;
        ans += f(v,target-v[i],dp,0);
        ans += f(v,target,dp,i+1);
        return t = ans;
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<vector<int>>dp(nums.size(),vector<int>(1001,-1));
        return f(nums,target,dp);
    }
};