class Solution {
public:
    int ans = INT_MAX;
    bool vis[100001];
    vector<pair<int,int>>adj[100001];
    void dfs(int v){
        vis[v] = 1;
        for(auto i:adj[v]){
            ans = min(ans,i.second);
            if(vis[i.first]==0){
                dfs(i.first);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& v) {
        memset(vis,0,sizeof(vis));
        for(auto i:v){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        dfs(1);
        return ans;
    }
};