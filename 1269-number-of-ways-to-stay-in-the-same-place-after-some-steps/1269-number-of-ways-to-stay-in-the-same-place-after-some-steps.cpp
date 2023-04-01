const int mod = 1e9+7;
#define ll long long
int dp[501][1000];
class Solution {
public:
    int f(int s,int a,int i=0){
        if(s==0 && i==0) return 1;
        if(s==0||i<0||i==a) return 0;
        auto &it = dp[s][i];
        if(it!=-1)return it;
        ll res = 0;
        res += f(s-1,a,i);
        res %= mod;
        res+=f(s-1,a,i+1);
        res %= mod;
        res+=f(s-1,a,i-1);
        res %= mod;
        return it= res;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return f(steps,arrLen);
    }
};



