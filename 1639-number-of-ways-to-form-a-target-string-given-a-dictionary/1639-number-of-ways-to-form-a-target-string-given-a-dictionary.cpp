class Solution {
public:
    const int mod = 1e9+7;
    int dp[1001][1001];
    int f(vector<vector<int>>&has,string &target,int i=0,int j=0){
        if(i==target.size()) return 1;
        if(j==has.size()) return 0;
        int &t = dp[i][j];
        if(t!=-1) return t;
        long long res = 0;
        res += f(has,target,i,j+1);
        res %= mod;
        if(has[j][target[i]-'a']>0){
            res += (1LL*has[j][target[i]-'a'])*f(has,target,i+1,j+1);
            res %= mod;
        }
        return t=res;
    }
    int numWays(vector<string>& words, string target){
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>has(words[0].size(),vector<int>(26));
        for(int i=0;i<words[0].size();i++){
            for(int j=0;j<words.size();j++){
                has[i][words[j][i]-'a']++;
            }
        }
        return f(has,target);
    }
};