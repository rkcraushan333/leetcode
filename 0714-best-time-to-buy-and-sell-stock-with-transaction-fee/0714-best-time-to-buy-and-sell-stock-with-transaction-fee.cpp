class Solution {
public:
    int dp[50001][2];
    int f(vector<int>&v,int fee,int i=0,bool b=0)
    {
        if(i==v.size()) return 0;
        int &rkc = dp[i][b];
        if(rkc!=-1) return rkc;
        int ans = 0;
        if(!b)
        {
            ans = max(ans,(-1)*v[i]+f(v,fee,i+1,b^1));
            ans = max(ans,f(v,fee,i+1,b));
        }
        else
        {
            ans = max(ans,v[i]-fee+f(v,fee,i+1,b^1));
            ans = max(ans,f(v,fee,i+1,b));
        }
        return rkc=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return f(prices,fee);
    }
};