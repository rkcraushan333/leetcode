class Solution {
public:
    int dp[101][201];
    const int mod = 1e9+7;
    int f(vector<int>&v,int l,int e,int fuel)
    {
        int &rkc = dp[l][fuel];
        if(rkc!=-1) return rkc;
        int ans = 0;
        if(l==e)
        {
            ans++;
            ans %= mod;
        }
        for(int j=0;j<v.size();j++)
        {
            if(l==j) continue;
            int c = fuel-abs(v[l]-v[j]);
            if(c>=0) 
            {
                ans += f(v,j,e,c);
                ans %= mod;
            }
        }
        return rkc=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        memset(dp,-1,sizeof(dp));
        return f(locations,start,finish,fuel);
    }
};