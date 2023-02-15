class Solution {
public:
    vector<pair<int,int>>v;
    int dp[601][101][101];
    int f(int m,int n,int i=0){
        if(i==v.size()){
            return 0;
        }
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        if(m>=v[i].first && n>=v[i].second){
            return dp[i][m][n]=max(1+f(m-v[i].first,n-v[i].second,i+1),f(m,n,i+1));
        }else{
            return dp[i][m][n]=f(m,n,i+1);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        for(auto i:strs){
            int a = 0,b =0;
            for(auto j:i){
                if(j=='0') a++;
                else b++;
            }
            v.push_back({a,b});
        }
        return f(m,n);
    }
};