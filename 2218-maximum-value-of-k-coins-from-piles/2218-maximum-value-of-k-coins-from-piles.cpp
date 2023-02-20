class Solution {
public:
    int dp[1001][2001];
    int f(vector<vector<int>>&v,int k,int i=0){
        if(k==0) return 0;
        if(i==v.size()) return INT_MIN;
        int &t = dp[i][k];
        if(t!=-1) return t;
        int res = INT_MIN;
        res = max(res,f(v,k,i+1));
        int curr = 0;
        for(int idx=0;idx<v[i].size();idx++){
            if(idx+1>k) break;
            curr += v[i][idx];
           res = max(res,curr+f(v,k-idx-1,i+1));
        }        
        return t = res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return f(piles,k);
    }
};