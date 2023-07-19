class Solution {
public:
    int dp[100001];
    vector<int>v1;
    int f(vector<vector<int>>&v,int i=0)
    {
        if(i==v.size()) return 0;
        int &rkc = dp[i];
        if(rkc!=-1) return rkc;
        int ans = 1e9;
        ans = min(ans,1+f(v,i+1));
        int t = lower_bound(v1.begin(),v1.end(),v[i][1])-v1.begin();
        ans = min(ans,t-i-1+f(v,t));
        return rkc = ans;
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) 
    {
        memset(dp,-1,sizeof(dp));
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            v1.push_back(v[i][0]);
        }
        return f(v);
    }
};