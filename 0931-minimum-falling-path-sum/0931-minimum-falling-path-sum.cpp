class Solution {
public:
    int dp[101][101];
    int dy[3] = {0,1,-1};
    int f(vector<vector<int>>&matrix,int i,int j){
        if(i==matrix.size()) return 0;
        if(j<0||j==matrix.size()) return 1e7;
        int &t = dp[i][j];
        if(t!=-1) return t;
        int res = INT_MAX;
        for(int k=0;k<3;k++){
            int c = matrix[i][j]+f(matrix,i+1,j+dy[k]);
            res = min(res,c);
        }
        return t=res;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        for(int i=0;i<matrix[0].size();i++) {
            memset(dp,-1,sizeof(dp));
            res = min(res,f(matrix,0,i));
        }
        return res;
    }
};