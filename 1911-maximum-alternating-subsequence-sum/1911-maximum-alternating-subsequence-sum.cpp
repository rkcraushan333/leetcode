class Solution {
public:
    #define ll long long
    ll dp[100001][2];
    ll f(vector<int>&v,int i = 0,bool c = 0)
    {
        if(i==v.size()) return 0;
        ll &rkc = dp[i][c];
        if(rkc!=-1) return rkc;
        ll ans = 0;
        if(c)
        {
            ans = max(ans,-v[i]+f(v,i+1,c^1));
            ans = max(ans,f(v,i+1,c));
        }
        else
        {
            ans = max(ans,v[i]+f(v,i+1,c^1));
            ans = max(ans,f(v,i+1,c));
        }
        return rkc = ans;
    }
    ll maxAlternatingSum(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        return f(nums);
    }
};