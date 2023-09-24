class Solution {
public:
    map<pair<int,int>,double>dp;
    double f(double t,int r,int c)
    {
        if(r==0&&c==0)
            return t;
        if(r<0||c<0||r<c)
            return 0.0;
        if(dp.count({r,c})) return dp[{r,c}];
        
        double a = (f(t,r-1,c)-1.0)/2.0;
        double b = (f(t,r-1,c-1)-1.0)/2.0;
        a = max(0.0,a); b = max(0.0,b);
        return dp[{r,c}] = a+b;
    }
    double champagneTower(int t, int r, int c) 
    {
        double t1 = t;
        return min(1.0,f(t1,r,c));
    }
};