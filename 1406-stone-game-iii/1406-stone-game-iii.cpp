class Solution {
public:
    int dp[500001][2];
    int f(vector<int>&v,int i=0,bool a=1){
        if(i>=v.size()) return 0;
        if(dp[i][a]!=-1) return dp[i][a];
        if(a){
            int res = INT_MIN;
            int temp = 0;
            for(int k=0;k<3;k++){
                if(i+k>=v.size()) break;
                temp += v[i+k];
                res = max(res,temp+f(v,i+k+1,!a));
            }
            return dp[i][a]=res;
        }else{
            int res = INT_MAX;
            for(int k=0;k<3;k++){
                if(i+k>=v.size()) break;
                res = min(res,f(v,i+k+1,!a));
            }
            return dp[i][a]=res;
        }
    }
    string stoneGameIII(vector<int>& t) {
        int sum = accumulate(t.begin(),t.end(),0);
        memset(dp,-1,sizeof(dp));
        int res = f(t);
        if(res==sum-res) return "Tie";
        else if(res>sum-res) return "Alice";
        return "Bob";
    }
};