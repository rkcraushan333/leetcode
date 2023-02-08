class Solution {
public:
    int dp[50001];
    vector<bool>vis;
    bool f(vector<int>&v,int s){
        if(s<0||s>=v.size()||vis[s]) return false;
        vis[s] = 1;
        if(v[s]==0) return true;
        if(dp[s]!=-1) return dp[s];
        if(f(v,s+v[s])||f(v,s-v[s])) return dp[s]=true;
        return dp[s]=false;
    }
    bool canReach(vector<int>& arr, int start) {
        memset(dp,-1,sizeof(dp)); 
        vis.resize(arr.size()+1);
        return f(arr,start);
    }
};