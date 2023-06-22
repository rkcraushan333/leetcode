// Good memoization question
class Solution {
public:
    int dp[1<<20][2];
    bool f(int mx,int t,int mask=0,bool b=0)
    {
        int &rkc = dp[mask][b];
        if(rkc!=-1) return rkc;
        int curr = 0;
        for(int i=0;i<mx;i++)
        {
            if(mask&(1<<i)) 
            {
                curr += (i+1);
            }
        }
        if(curr>=t)
        {
            if(b) 
            {
                return rkc=true;
            }
            else 
            {
                return rkc=false;
            }
        }
        bool ans;
        if(!b)
        {
            ans = false;
            for(int i=0;i<mx;i++)
            {
                if(mask&(1<<i)) continue;
                ans |= f(mx,t,mask|(1<<i),b^1);
            }
        }
        else 
        {
            ans = true;
            for(int i=0;i<mx;i++)
            {
                if(mask&(1<<i)) continue;
                ans &= f(mx,t,mask|(1<<i),b^1);
            }
        }
        return rkc = ans;
    }
    bool canIWin(int mx, int t) 
    {
        if((mx*(mx+1))/2<t) return false;
        if(mx>=t) return true;
        memset(dp,-1,sizeof(dp));
        return f(mx,t);
    }
};