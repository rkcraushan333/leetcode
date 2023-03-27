class Solution {
public:
    int dp[201][201];
    int f(vector<vector<int>>&v,int n,int m){
        if(n<0||m<0) return 1e8;
        if(n==0 && m==0) return v[0][0];
        int &t = dp[n][m];
        if(t!=-1) return t;
        return t=min(v[n][m]+f(v,n-1,m),v[n][m]+f(v,n,m-1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(grid,grid.size()-1,grid[0].size()-1);
    }
};