class Solution {
public:
    int dp[1001][1001];
    string s,t;
    int f(int i=0,int j=0){
        if(i==s.size()||j==t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res = 0;
        if(s[i]==t[j])
            res = max(res,1+f(i+1,j+1));
        res = max(res,f(i,j+1));
        res = max(res,f(i+1,j));
        return dp[i][j]=res;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        s = text1;
        t = text2;
        return f();
    }
};