class Solution {
public:
    int dp[1001][101][2];
    int f(int k,vector<int>&p,int i=0,bool b = 1){
        if(k==0 || i==p.size()) return  0;
        int &t = dp[i][k][b];
        if(t!=-1) return t;
        int res = 0;
        if(b){
            res = max(res,(-1*p[i])+f(k,p,i+1,0));
            res = max(res,f(k,p,i+1,1));
        }
        else{
            res = max(res,p[i]+f(k-1,p,i+1,1));
            res = max(res,f(k,p,i+1,0));
        }
        return  t=res;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(k,prices);
    }
};