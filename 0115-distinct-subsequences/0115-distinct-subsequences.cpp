class Solution {
public:
    int dp[1001][1001];
    int f(string &s,string &t,int i=0,int j=0)
    {
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        int &rkc = dp[i][j];
        if(rkc!=-1) return rkc;
        int ans = 0;
        if(s[i]==t[j])
        {
            ans += f(s,t,i+1,j+1);
            ans += f(s,t,i+1,j);
        }
        else
        {
            ans += f(s,t,i+1,j);
        }
        return rkc = ans;        
    }
    int numDistinct(string &s, string &t)
    {    
        memset(dp,-1,sizeof(dp));
        return f(s,t);
    }
};