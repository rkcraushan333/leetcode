class Solution {
public:
    int dp[201][202];
    int f(vector<vector<int>>&grid,int i,int last){
        if(i==grid.size()) return 0;
        int &cc = dp[i][last+1];
        if(cc!=-1) return cc;
        int res = INT_MAX;
        for(int j=0;j<grid[0].size();j++){
            if(last==-1)
               {
                int t = grid[i][j] + f(grid,i+1,j);
                res = min(res,t);
               }
            else{
                if(last!=j){
                    int t = grid[i][j] + f(grid,i+1,j);
                    res = min(res,t);
                }
            }
        }
        return cc = res;
    }
    int minFallingPathSum(vector<vector<int>>& grid){
        memset(dp,-1,sizeof(dp));
        return f(grid,0,-1);
    }
};