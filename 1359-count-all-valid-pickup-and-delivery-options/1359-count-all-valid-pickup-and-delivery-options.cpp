class Solution {
public:
    const int mod = 1e9+7;
    #define ll long long
    ll dp[501][501];
    ll f(int p,int d)
    {
        if(p==0&&d==0) return 1;
        ll &rkc = dp[p][d];
        if(rkc!=-1) return rkc;
        ll ans = 0;
        ll a = p,b = d;
        if(p) ans += (a*f(p-1,d+1))%mod;
        ans %= mod;
        if(d) ans += (b*f(p,d-1))%mod;
        ans %= mod;
        return rkc = ans;
    }
    int countOrders(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return f(n,0);
    }
};