class Solution {
public:
    const int mod = 1e9+7;
    int dp[101][101][101];
    int f(int n,int mn,vector<int>&g,vector<int>&p,int i=0){
        if(i==g.size()){
            return mn==0;
        }
        long long ans = 0;
        int &t = dp[i][n][mn];
        if(t!=-1) return t;
        ans += f(n,mn,g,p,i+1);
        ans %= mod;
        if(n>=g[i]){
            ans += f(n-g[i],max(mn-p[i],0),g,p,i+1); // keep mn always zero 
            ans %= mod;
        }
        return t=ans;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return f(n,minProfit,group,profit);
    }
};