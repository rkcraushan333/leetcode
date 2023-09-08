class Solution {
public:
    int a[9] = {0,0,0,1,1,1,-1,-1,-1};
    int b[9] = {0,1,-1,0,1,-1,0,1,-1};
    int dp[71][71][71];
    int f(vector<vector<int>>&v,int n,int m,int i,int j1,int j2)
    {
        if(j1<0||j1>=m||j2<0||j2>=m) return -1e9;
        if(i==n-1) 
        {
            if(j1==j2) return v[i][j1];
            return v[i][j1]+v[i][j2];
        }
        int &rkc = dp[i][j1][j2];
        if(rkc!=-1) return rkc;
        int ans = 0,curr=0;
        curr += v[i][j1]+v[i][j2];
        if(j1==j2) curr -= v[i][j1];
        for(int k=0;k<9;k++)
        {
            ans = max(ans,curr+f(v,n,m,i+1,j1+a[k],j2+b[k]));
        }
        return rkc = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        return f(grid,n,m,0,0,m-1);
    }
};