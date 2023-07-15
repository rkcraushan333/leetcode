class Solution {
public:
    int solve(int ind,vector<int>&v,int end,vector<int>&dp)
{
    if(ind>end)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int pick=v[ind]+solve(ind+2,v,end,dp);
    int notPick=solve(ind+1,v,end,dp);
    return dp[ind]=max(pick,notPick);
}
    int rob(vector<int>& v) {
    if(v.size()==1)
    {
        return v[0];
    }
    int n=v.size();
    vector<int>dp(n,-1);
    vector<int>dp1(n,-1);
    return max(solve(0,v,n-2,dp),solve(1,v,n-1,dp1));
    }
};