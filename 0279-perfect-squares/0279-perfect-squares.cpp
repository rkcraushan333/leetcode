class Solution {
public:
    vector<int>v;
    int dp[101][10001];
    int f(int n,int i=0){
        if(n==0) return 0;
        if(i==v.size()) return 1e8;
        int &t = dp[i][n];
        if(t!=-1) return t;
        int res = 1e8;
        res= min(res,f(n,i+1));
        if(n>=v[i]){
            res= min(res,1+f(n-v[i],i));
        }
        return dp[i][n]=res;
    }
    int numSquares(int n) {
        for(int i=1;i<101;i++){
            v.push_back(i*i);
        }
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};