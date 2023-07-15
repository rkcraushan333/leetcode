class Solution {
public:
    #define ll long long
    ll dp[30001];
    ll f(vector<vector<int>>&v,vector<int>&st,int n,int i=0)
    {
        if(i==v.size()||v[i][1]>n) return 0;
        ll &rkc = dp[i];
        if(rkc!=-1) return rkc;
        ll ans = 0;
        ans = max(ans,f(v,st,n,i+1));
        int t = lower_bound(st.begin(),st.end(),v[i][1])-st.begin();
        ans = max(ans,v[i][2]+v[i][1]-v[i][0]+f(v,st,n,t));
        return rkc = ans;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        sort(rides.begin(),rides.end());
        vector<int>st;
        for(auto i:rides)
        {
            st.push_back(i[0]);
        }
        memset(dp,-1,sizeof(dp));
        return f(rides,st,n);
    }
};