class Solution {
public:
    int dp[501][501];
    int f(string &s, string &t,int i=0,int j=0){
        if(i==s.size()&&j==t.size()) return 0;
        if(i==s.size()) return t.size()-j;
        if(j==t.size()) return s.size()-i;
        int &tt = dp[i][j];
        if(tt!=-1) return tt;
        int res = 1e7;
        if(s[i]==t[j])
            res = min(res,f(s,t,i+1,j+1));
        else{
            res = min(res,1+f(s,t,i+1,j+1));
            res = min(res,1+f(s,t,i,j+1));
            res = min(res,1+f(s,t,i+1,j));
        }
        return tt = res;
    }
    int minDistance(string &s, string &t) {
        memset(dp,-1,sizeof(dp));
        return f(s,t);
    }
};