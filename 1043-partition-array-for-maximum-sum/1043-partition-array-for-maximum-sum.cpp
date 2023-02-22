class Solution {
public:
    int dp[501];
    int f(int k,vector<int>&v,int i=0){
        if(i==v.size()) return 0;
        int &t = dp[i];
        if(t!=-1) return t;
        int c = 0,res =0;
        for(int j=i;j<v.size();j++){
            if(j-i+1>k) break;
            c = max(c,v[j]);
            res = max(res,c*(j-i+1)+f(k,v,j+1));
        }
        return t=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return f(k,arr);
    }
};