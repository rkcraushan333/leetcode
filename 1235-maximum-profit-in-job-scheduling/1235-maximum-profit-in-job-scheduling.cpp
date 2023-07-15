class Solution {
public:
    int dp[50001];
    vector<vector<int>>v;
    int f(vector<int>&s,int i=0)
    {
        if(i==s.size()) return 0;
        int &rkc = dp[i];
        if(rkc!=-1) return rkc;
        int ans = 0;
        ans = max(ans,f(s,i+1));
        int t = lower_bound(s.begin(),s.end(),v[i][1])-s.begin();
        ans = max(ans,v[i][2]+f(s,t));
        return rkc = ans;
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) 
    {
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({s[i],e[i],p[i]});
        }       
        sort(v.begin(),v.end());
        sort(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));
        return f(s);
    }
};