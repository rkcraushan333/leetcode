class Solution {
public:
    int dp[51][51][51][51];
    int f(vector<vector<int>>&grid,int i1,int j1,int i2,int j2)
    {
        int n = grid.size();
        if(i1==n||j1==n||i2==n||j2==n||grid[i1][j1]==-1||grid[i2][j2]==-1) return -1e9;
        if(i1==n-1&&j1==n-1&&i2==n-1&&j2==n-1) return grid[i1][j1];
        int &rkc = dp[i1][j1][i2][j2];
        if(rkc!=-1) return rkc;
        int ans = -1e9,cnt=0;
        if(grid[i1][j1]==1) cnt++;
        if(grid[i2][j2]==1) cnt++;
        if(i1==i2&&j1==j2) if(grid[i1][j1]==1) cnt--;
        ans = max(ans,cnt+f(grid,i1+1,j1,i2+1,j2));
        ans = max(ans,cnt+f(grid,i1+1,j1,i2,j2+1));
        ans = max(ans,cnt+f(grid,i1,j1+1,i2+1,j2));
        ans = max(ans,cnt+f(grid,i1,j1+1,i2,j2+1));
        return rkc = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof(dp));
        int x = f(grid,0,0,0,0);
        return x>0?x:0;
    }
};