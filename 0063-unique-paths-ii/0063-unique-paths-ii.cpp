class Solution {
public:
int f(int i,int j,int m,int n,vector<vector<int>>&v,vector<vector<int>>&dp)
{
    if(i>m-1 ||j>n-1)
        return 0;
    if(i==m-1 && j==n-1)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=f(i,j+1,m,n,v,dp)+f(i+1,j,m,n,v,dp);
    return dp[i][j];
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {        
int n=obstacle.size();
int m=obstacle[0].size();
vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(obstacle[i][j])
            {
                dp[i][j] = 0;
            }
        }
    }
    if(dp[n-1][m-1]==0) return 0;
    return f(0,0,n,m,obstacle,dp);
}
};