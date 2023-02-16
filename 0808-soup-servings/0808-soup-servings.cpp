class Solution {
public:
    vector<vector<double>>dp;
    double f(int a,int b){
        if(a<=0 && b<=0) 
            return 0.5;
        if(a<=0)
            return 1.0;
        if(b<=0) 
            return 0.0;
        if(dp[a][b]!=-1) return dp[a][b];
        return dp[a][b]=(f(a-100,b)+f(a-75,b-25)+f(a-50,b-50)+f(a-25,b-75))/4;
    }
    double soupServings(int n) {
        if(n>4800) return 1;
        dp.resize(n+1,vector<double>(n+1,-1));
        return f(n,n);
    }
};