// length - Longest palindromic subsequence
class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                dp[i][j] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j]);
                dp[i][j] = max(dp[i][j-1],dp[i][j]);
                if(s[i-1]==t[j-1]) dp[i][j] = max(dp[i][j],1+dp[i-1][j-1]);
            }
        }
        return s.size()-dp[n][n];
    }
};