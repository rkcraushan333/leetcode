class Solution {
public:
    int res = 0;
    vector<vector<pair<int,int>>>adj;
    vector<bool>vis;
    void dfs(int s){
        vis[s] = 1;
        for(auto i:adj[s]){
            if(!vis[i.first]) {
                res += i.second;
                dfs(i.first);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections){
        adj.resize(n);
        vis.resize(n);
        for(auto v:connections){
            adj[v[0]].push_back({v[1],1});
            adj[v[1]].push_back({v[0],0});
        }
        dfs(0);
        return res;
    }
};