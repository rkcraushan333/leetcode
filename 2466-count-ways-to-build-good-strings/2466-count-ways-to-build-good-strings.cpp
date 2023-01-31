class Solution {
public:
    const int mod = 1e9+7;
    int dp[100001];
    int f(int l,int h,int z,int o,int k=0){
        if(k>h) return 0;
        if(dp[k]!=-1) return dp[k];
        if(k>=l && k<=h) return dp[k]=(1+(f(l,h,z,o,k+z)%mod+f(l,h,z,o,k+o)%mod)%mod)%mod;
        else return dp[k]=(f(l,h,z,o,k+z)%mod+f(l,h,z,o,k+o)%mod)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return f(low,high,zero,one);
    }
};