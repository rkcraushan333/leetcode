class Solution {
public:
    int dp[10][2][2][2][1<<10];
    int f(string &s,int i=0,bool last=1,bool rep=0,bool lz=1,int hash=0)
    {
        if(i==s.size())
        {
            return rep;
        }
        int &rkc = dp[i][last][rep][lz][hash];
        if(rkc!=-1) return rkc;
        int ans = 0;
        int limit = last?s[i]-'0':9;
        for(int j=0;j<=limit;j++)
        {
            if(lz)
            {
                if(j==0)
                {
                    ans += f(s,i+1,last&(limit==j),0,1,0);
                }
                else
                {
                    ans += f(s,i+1,last&(limit==j),0,0,hash|(1<<j));
                }
            }
            else
            {
                if(hash&(1<<j))
                {
                    ans += f(s,i+1,last&(limit==j),1,0,hash|(1<<j));
                }
                else
                {
                    ans += f(s,i+1,last&(limit==j),rep,0,hash|(1<<j));
                }
            }
        }
        return rkc = ans;
    }
    int f1(int n)
    {
        string s= to_string(n);
        memset(dp,-1,sizeof(dp));
        return f(s);
    }
    int numDupDigitsAtMostN(int n) 
    {    
        return f1(n);
    }
};