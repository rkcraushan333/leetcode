class Solution {
public:
    int dp[31][10001];
    int f(vector<int>&v,int k,int i=0){
        if(k==0||i==v.size()) return 0;
        int &t = dp[i][k];
        if(t!=-1) return t;
        int res = 0;
        res = max(res,f(v,k,i+1));
        if(k>=v[i]){
            res = max(res,v[i]+f(v,k-v[i],i+1));
        }
        return t=res;
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int s = accumulate(stones.begin(),stones.end(),0);
        return s -2*f(stones,s/2);
    }
};