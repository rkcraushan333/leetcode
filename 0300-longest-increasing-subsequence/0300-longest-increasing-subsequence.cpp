class Solution {
public:
    int dp[2503][2503];
    int f(vector<int>&v,int i,int last){
        if(i==v.size()) return 0;
        if(dp[i][last]!=-1) return dp[i][last];
        if(v[i]>v[last]) 
            return dp[i][last]=max(1+f(v,i+1,i),f(v,i+1,last));
        else 
            return dp[i][last]=f(v,i+1,last);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.push_back(-10001);
        return f(nums,0,nums.size()-1);
    }
};