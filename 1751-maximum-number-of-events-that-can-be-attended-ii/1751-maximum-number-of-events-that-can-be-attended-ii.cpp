class Solution {
public:
    int f(vector<vector<int>>&v,vector<int>&s,vector<vector<int>>&dp,int k,int i=0)
    {
        if(i==v.size()||k==0) return 0;
        int &rkc = dp[i][k];
        if(rkc!=-1) return rkc;
        int ans = 0;
        ans = max(ans,f(v,s,dp,k,i+1));
        int t = upper_bound(s.begin(),s.end(),v[i][1])-s.begin();
        ans = max(ans,v[i][2]+f(v,s,dp,k-1,t));
        return rkc = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) 
    {
        sort(events.begin(),events.end());
        vector<int>st;
        int n = events.size();
        for(int i=0;i<n;i++)
        {
            st.push_back(events[i][0]);
        }
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return f(events,st,dp,k);
    }
};