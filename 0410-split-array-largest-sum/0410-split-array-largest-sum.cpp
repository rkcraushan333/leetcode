class Solution {
public:
    int dp[1001][51];
    int f(int k,vector<int>&v,int i=0){
        if(k==0 && i==v.size()) return INT_MIN;
        if(k==0||i==v.size()) return INT_MAX;
        int &t = dp[i][k];
        if(t!=-1) return t; 
        int res = INT_MAX;
        int s=0;
        for(int j=i;j<v.size();j++){
            s+=v[j];
            res = min(res,max(s,f(k-1,v,j+1)));
        }
        return t=res;
    }
    int splitArray(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return f(k,nums); 
    }
};