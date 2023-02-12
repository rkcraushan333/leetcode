const int M = 100001;
int k;
class Solution {
public:
    long long ans;
    vector<int>adj[M];
    vector<bool>vis;
    long long dfs(int s=0){
        if(vis[s]) return 1;
        vis[s] = 1;
        long long res = 0;
        for(auto i:adj[s])
             res += dfs(i);
        if(s!=0) ans += (res+k-1)/k;
        return res;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vis.resize(M);
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        k = seats;
        dfs();
        return ans;
    }
};