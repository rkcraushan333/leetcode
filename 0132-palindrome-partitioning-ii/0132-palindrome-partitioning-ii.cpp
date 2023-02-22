class Solution {
public:
    int dp1[2001][2001];
    bool isPal(string &s,int i,int j){
        if(i==j) return true;
        if(i+1==j) return s[i]==s[j];
        int &t1 = dp1[i][j];
        if(t1!=-1) return t1;
        return t1=(s[i]==s[j]) & isPal(s,i+1,j-1);
    }
    int dp[2001];
    int f(string &s,int i=0){
        if(i==s.size()) return 0;
        int res = INT_MAX;
        int &t = dp[i];
        if(t!=-1) return t;
        for(int j=i;j<s.size();j++){
            if(isPal(s,i,j)){
                res = min(res,1+f(s,j+1));
            }
        }
        return t=res;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp1));
        return f(s)-1;
    }
};