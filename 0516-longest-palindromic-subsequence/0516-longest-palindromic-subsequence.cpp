class Solution {
public:
    int dp[1001][1001];
    int f(string &s,string &t,int i=0,int j=0){
        if(i==s.size()||j==t.size()) return 0;
        int &tt = dp[i][j];
        if(tt!=-1) return tt;
        int res = 0;
        res = max(res,f(s,t,i+1,j));
        res = max(res,f(s,t,i,j+1));
        if(s[i]==t[j])  res = max(res,1 + f(s,t,i+1,j+1));
        return tt = res;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        string t = s;
        reverse(t.begin(),t.end());
        return f(s,t);
    }
};