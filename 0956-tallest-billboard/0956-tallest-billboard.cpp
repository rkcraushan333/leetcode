// Keep Track of the distance
class Solution {
public:
    int dp[21][10001];
    int f(vector<int>&v,int i=0,int d=0)
    {
        if(i==v.size())
        {
            if(d==0) return 0;
            return -1e9;
        }
        int &rkc = dp[i][d+5000];
        if(rkc!=-1) return rkc;
        int ans = INT_MIN;
        // Ignoring
        ans = max(ans,f(v,i+1,d));
        // Taking first
        ans = max(ans,v[i]+f(v,i+1,d+v[i]));
        // Taking second
        ans = max(ans,f(v,i+1,d-v[i]));
        return rkc = ans;
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return f(rods);
    }
};