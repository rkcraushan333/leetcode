class Solution {
public:
    int dp[10001];
    int f(vector<int>&v,int i=0){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(i==v.size()-1) return 0;
        int res = 1e8;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=v[i];j++){
            if(i+j>=v.size()) break;
            res = min(res,1+f(v,i+j));
        }
        return dp[i]=res;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(nums);
    }
};