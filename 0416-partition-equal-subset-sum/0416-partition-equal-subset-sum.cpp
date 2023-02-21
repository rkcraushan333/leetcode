class Solution {
public:
    int dp[201][20001];
    int f(vector<int>&v,int s,int i=0){
        if(i==v.size()||s==0) return 0;
        int &t = dp[i][s];
        if(t!=-1) return t;
        int res = 0;
        res = max(res, f(v,s,i+1));
        if(s>=v[i]){
            res = max(res,v[i]+f(v,s-v[i],i+1));
        }
        return t=res;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return 0;
        memset(dp,-1,sizeof(dp));
        return sum/2 == f(nums,sum/2);
    }
};