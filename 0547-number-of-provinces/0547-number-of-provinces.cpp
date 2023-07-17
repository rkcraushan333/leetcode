class Solution {
public:
    vector<vector<int>>adj;
    vector<bool>vis;
    void dfs(int s)
    {
        vis[s] = 1;
        for(auto i:adj[s])
        {
            if(!vis[i]) dfs(i);
        }
    }
    int findCircleNum(vector<vector<int>>& v) 
    {
        int n = v.size();
        adj.resize(n);
        vis.resize(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(v[i][j])
                    {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};