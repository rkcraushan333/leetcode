class Solution {
public:
        // if(i==s.size()||j==t.size()) return 0;
        // if(s[i]==t[j])
        //     res = max(res,1+f(i+1,j+1));
        // res = max(res,f(i,j+1));
        // res = max(res,f(i+1,j));
        // return res;
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(),m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};