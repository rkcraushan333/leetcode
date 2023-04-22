// length - Longest palindromic subsequence
class Solution {
public:
    int dp[501][501];
    int f(string &s,string &t,int i=0,int j=0){
        if(i==s.size()||j==s.size()) return 0;
        int &tt = dp[i][j];
        if(tt!=-1) return tt;
        int ans =0;
        ans = max(ans,f(s,t,i,j+1));
        ans = max(ans,f(s,t,i+1,j));
        if(s[i]==t[j]) ans = max(ans,1+f(s,t,i+1,j+1));
        return tt=ans;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        string t = s;
        reverse(t.begin(),t.end());
        return s.size()-f(s,t);
    }
};