class Solution {
public:
    int dp[2501][2502];
    int f(vector<int>&v,int i=0,int pre=-1)
    {
        if(i==v.size()) return 0;
        int &rkc = dp[i][pre+1];
        if(rkc!=-1) return rkc;
        int ans = 0;
        if(pre==-1)
        {
            ans = max(ans,1+f(v,i+1,i));
            ans = max(ans,f(v,i+1,pre));
        }
        else
        {
            if(v[i]>v[pre])
            {
                ans = max(ans,1+f(v,i+1,i));
                ans = max(ans,f(v,i+1,pre));
            }
            else
            {
                ans = max(ans,f(v,i+1,pre));
            }
        }
        return rkc = ans;
    }
    int lengthOfLIS(vector<int>& nums)
    {
        memset(dp,-1,sizeof(dp));
        return f(nums);
    }
};