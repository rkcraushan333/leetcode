class Solution {
public:
    const int mod=1e9+7;
    int dp[5001][7][16];
    int f(int n,vector<int>&roll,int l=0,int cnt=0){
        if(n==0)
            return 1;
        int &t = dp[n][l][cnt];
        if(t!=-1) return t;
        long long ans = 0;
        for(int i=1;i<=6;i++){
            if(l==i){
                if(cnt < roll[i-1]){
                   ans = (ans+ f(n-1,roll,i,cnt+1))%mod;
                 }
                continue;
            }
            ans = (ans+f(n-1,roll,i,1))%mod;
        }
        return t=ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return f(n,rollMax);
    }
};