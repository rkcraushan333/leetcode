class Solution {
public:
    int dp[301][5001];
    int f(int k,vector<int>&v,int i=0){
        if(k==0) return 1;
        if(i==v.size()) return 0;
        int &t = dp[i][k];
        if(t!=-1) return t;
        int res = 0;
        res+=f(k,v,i+1);
        if(k>=v[i]) res+=f(k-v[i],v,i);
        return t=res;
    }
    int change(int amount, vector<int>& coins){
        memset(dp,-1,sizeof(dp));
        return f(amount,coins);
    }
};