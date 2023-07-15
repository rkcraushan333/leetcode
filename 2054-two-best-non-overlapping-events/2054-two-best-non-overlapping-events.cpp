class Solution {
public:
    int dp[100001][2];
    int f(vector<vector<int>>&v,vector<int>&s,int k = 0,int i=0)
    {
        if(k==2||i==v.size()) return 0;
        int &rkc = dp[i][k];
        if(rkc!=-1) return rkc;
        int ans = 0;
        ans = max(ans,f(v,s,k,i+1));
        int t = upper_bound(s.begin(),s.end(),v[i][1])-s.begin();
        ans = max(ans,v[i][2]+f(v,s,k+1,t));
        return rkc = ans;
    }
    int maxTwoEvents(vector<vector<int>>& events)
    {
        vector<int>st;
        for(auto v:events)
        {
            st.push_back(v[0]);
        }
        sort(st.begin(),st.end());
        sort(events.begin(),events.end());
        memset(dp,-1,sizeof(dp));
        return f(events,st);
    }
};