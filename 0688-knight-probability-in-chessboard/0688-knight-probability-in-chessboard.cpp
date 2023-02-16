class Solution {
public:
    int dx[8] = {-2,-1,1,2,2,1,-1,-2};
    int dy[8] = {1,2,2,1,-1,-2,-2,-1};
    double dp[101][26][26];
    double f(int n,int k,int r,int c){
        if(r<0||c<0||r>=n||c>=n)
            return 0.0;
        if(k==0) return 1;
        if(dp[k][r][c]!=0.0)
            return dp[k][r][c];
        double ans = 0.0;
        for(int i=0;i<8;i++)
        {
            ans += f(n,k-1,r+dx[i],c+dy[i]);
        }
        return dp[k][r][c]=ans/8;
    }
    double knightProbability(int n, int k, int r, int c) {
        memset(dp,0.0,sizeof(dp));
        return f(n,k,r,c);
    }
};