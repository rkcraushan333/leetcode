#define ll long long
const ll mod = 1e9+7;
ll dp[101][101];
class Solution {
public:
    ll f(int n,int t,int goal,int k)
    {
        if(goal==0) return n==0;
        ll &rkc = dp[n][goal];
        if(rkc!=-1) return rkc;
        ll ans = 0;
        if(n>0)
        {
            ans += f(n-1,t,goal-1,k)*n; ans %= mod;
        }
        if(t-n>k)
        {
            ans += f(n,t,goal-1,k)*(t-n-k); ans %= mod;
        }
        return rkc = ans;
    }
    int numMusicPlaylists(int n, int goal, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return f(n,n,goal,k);
    }
};