class Solution {
public:
    int dp[501][501];
    int f(string &s,string &t,int i=0,int j=0)
    {
        if(i==s.size()) return t.size()-j;
        if(j==t.size()) return s.size()-i;
        int &rkc = dp[i][j];
        if(rkc!=-1) return rkc;
        int ans = 1e8;
        // if same 
        if(s[i]==t[j])
        {
            ans = min(ans,f(s,t,i+1,j+1));
        }
        else
        {
            // insert in 1st
            ans = min(ans,1+f(s,t,i,j+1));
            // insert in 2nd
            ans = min(ans,1+f(s,t,i+1,j));
            // delete in 1st 
            // ans = min(ans,1+f(s,t,i+1,j));
            // // delete in 2nd
            // ans = min(ans,1+f(s,t,i,j+1));
            // // replace in 1st
            // ans = min(ans,1+f(s,t,i+1,j+1));
            // replace in 2nd 
            ans = min(ans,1+f(s,t,i+1,j+1));
        }
        return rkc = ans;
    }
    int minDistance(string &s, string &t) 
    {
        memset(dp,-1,sizeof(dp));
        return f(s,t);
    }
};