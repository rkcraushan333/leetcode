class Solution {
public:
    int dp[101][101];
    int f(int n,int m,int i=0,int j=0){
        if(i==n-1&&j==m-1) return 1;
        int &t = dp[i][j];
        if(t!=-1) return t;
        int res = 0;
        if(i<n-1) res += f(n,m,i+1,j);
        if(j<m-1) res += f(n,m,i,j+1);
        return t=res;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(m,n);
    }
};