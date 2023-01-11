class Solution {
public:
    vector<vector<int>>adj;
    int dfs(int node,vector<bool>& hasApple,int prev){
        int dis = 0;
        for(int &i:adj[node]){
            if(i!=prev){
                int temp = dfs(i,hasApple,node);
                if(hasApple[i]){
                    dis += (2+temp);
                    hasApple[node] = true;
                }
            }
        }
        return dis;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        for(vector<int> &v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        return dfs(0,hasApple,-1);
    }
};