class Solution {
public:
    bool f(string &s,string &p,vector<vector<int>>&dp,int i=0,int j=0)
    {
        if(i==s.size())
        {
            while(j<p.size())
            {
                if(p[j]!='*') return false;
                j++;
            }
            return true;
        }
        if(j==p.size())
        {
            return (i==s.size());
        }
        int &t = dp[i][j];
        if(t!=-1)
        {
            return t;
        }
        bool c = ((p[j]>='a')&&(p[j]<='z'));
        bool ans = false;
        if(c)
        {
            if(s[i]==p[j]) 
            {
                ans |= f(s,p,dp,i+1,j+1);
            }
            else
            {
                ans |= false;
            }
        }
        else
        {
            if(p[j]=='?')
            {
                ans |= f(s,p,dp,i+1,j+1);
            }
            else
            {
                for(int x=i;x<=s.size();x++)
                {
                    ans |= f(s,p,dp,x,j+1);
                }
            }
        }
        return t=ans;
    }
    bool isMatch(string s, string p) 
    {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return f(s,p,dp);
    }
};