class Solution {
public:
    double dp[25][25][101];
    int dx[8] = {1,1,-1,-1,2,2,-2,-2};
    int dy[8] = {2,-2,2,-2,1,-1,-1,1};
    double f(int i,int j,int n,int k)
    {
        if(i<0||j<0||i>=n||j>=n) return 0;
        if(k==0) return 1;
        double &t = dp[i][j][k];
        if(t!=0) return t;
        double ans=0;
        for(int x=0;x<8;x++)
        {
            ans += f(i+dx[x],j+dy[x],n,k-1)/8;
        }
        return t=ans;
    }
    double knightProbability(int n, int k, int r, int c) 
    {
        memset(dp,0.0,sizeof(dp));
        return f(r,c,n,k);
    }
};