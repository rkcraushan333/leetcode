class Solution {
public:
    const int mod = 1e9+7;
    int dp[501][501];
    int f(int p,int d)
    {
        if(p==0&&d==0) return 1;
        int &rkc = dp[p][d];
        if(rkc!=-1) return rkc;
        int ans = 0;
        int a = p,b = d;
        for(int i=0;i<a;i++)
        {
            ans += f(p-1,d+1);
            ans %= mod;
        }
        for(int i=0;i<b;i++)
        {
            ans += f(p,d-1);
            ans %= mod;
        }
        return rkc = ans;
    }
    int countOrders(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return f(n,0);
    }
};