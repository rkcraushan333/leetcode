class Solution {
public:
    int dp[1001][2001];
    int f(vector<vector<int>>&piles,int k,int i=0){
        if(k==0) return 0;
        if(i==piles.size()||k<0) return INT_MIN;
        int &t = dp[i][k];
        if(t!=-1) return t;
        int ans = 0,sum = 0;
        ans = max(ans,f(piles,k,i+1));
        for(int j=0;j<piles[i].size();j++){
            sum += piles[i][j];
            ans = max(ans,sum+f(piles,k-(j+1),i+1));
        }
        return t = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return f(piles,k);
    }
};