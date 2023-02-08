class Solution {
public:
    int dp[1001];
    int f(vector<int>&v,int d,int i){
        if(dp[i]!=-1) return dp[i];
        int res = 0;
        for(int j=1;j<=d;j++){
            if(i+j>=v.size() || v[i+j]>=v[i]) break;
            res = max(res,1 + f(v,d,i+j));
        }
        for(int j=1;j<=d;j++){
            if(i-j<0||v[i-j]>=v[i]) break;
            res = max(res,1 + f(v,d,i-j));
        }
        return dp[i]=res;
    }
    int maxJumps(vector<int>& arr, int d) {
        memset(dp,-1,sizeof(dp));
        int res = 0;
        for(int i=0;i<arr.size();i++){
            res = max(res,f(arr,d,i));
        }
        return res+1;
    }
};