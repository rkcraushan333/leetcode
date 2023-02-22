class Solution {
public:
    int dp[333][333];
    int f(vector<int>&v,int i,int j){
        if(i>=j) return 0;
        int &t = dp[i][j];
        if(t!=-1) return t;
        int res = INT_MIN;
        for(int k=i;k<j;k++){
            res = max(res,(v[i-1]*v[k]*v[j]) + f(v,i,k)+ f(v,k+1,j));
        }
        return t=res;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        return f(nums,1,nums.size()-1);
    }
};