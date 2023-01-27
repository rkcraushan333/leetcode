class Solution {
public:
    int dp[101][101][2];
    int f(vector<int>&s,int M=1,int i=0,bool a=1){
        if(i>=s.size()) return 0;
        int t = 0;
        if(dp[i][M][a]!=-1) return dp[i][M][a];
        if(a){
            int x = INT_MIN;
            for(int k=0;k<2*M;k++){
            if(i+k>=s.size())break;
            t += s[i+k];
            x = max(x,t+f(s,max(M,k+1),i+k+1,0));
        }
            return dp[i][M][a]=x;
        }else{
            int x = INT_MAX;
            for(int k=0;k<2*M;k++){
                if(i+k>=s.size()) break;
                x = min(x,f(s,max(M,k+1),i+k+1,1));
            }
            return dp[i][M][a]=x;
        }
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return f(piles);
    }
};