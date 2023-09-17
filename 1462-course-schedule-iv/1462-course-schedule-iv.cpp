class Solution {
public:
    vector<vector<int>>adj;
    bool dfs(int s,int l,vector<bool>&vis)
    {
        if(s==l) return true;
        vis[s] = 1;
        bool ans = 0;
        for(auto child:adj[s])
        {
            if(!vis[child])
            {
                ans |= dfs(child,l,vis);
            }
        }
        return ans;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>&p, vector<vector<int>>&q) 
    {
        adj.resize(n);
        for(int i=0;i<p.size();i++)
        {
            adj[p[i][0]].push_back(p[i][1]);
        }
        vector<bool>ans;
        for(int i=0;i<q.size();i++)
        {
            vector<bool>vis(n);
            ans.push_back(dfs(q[i][0],q[i][1],vis));
        }
        return ans;
    }
};