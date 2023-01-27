class Solution {
public:
    int dp[501][501][2];
    int f(int i,int j,vector<int>&v,bool a){
        if(i>=j) return 0;
        if(dp[i][j][a]!=-1) return dp[i][j][a];
        if(a){
            return dp[i][j][a]=max(v[i]+f(i+1,j,v,0),v[j]+f(i,j-1,v,0));
        }
        else 
            return dp[i][j][a]=min(f(i+1,j,v,1),f(i,j-1,v,1));
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(piles.begin(),piles.end(),0);
        int res = f(0,piles.size()-1,piles,1);
        return res>sum-res;
    }
};