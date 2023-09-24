class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>>dp(101,vector<double>(101));
        dp[0][0] = poured;
        for(int i=1;i<101;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[i-1][j]>1.0)
                {
                    double d = (dp[i-1][j]-1.0)/2;
                    dp[i][j] += d;
                    dp[i][j+1] += d;
                }
            }
        }
        return min(1.0,dp[query_row][query_glass]);
    }
};