// Reverse the degree and then topo sort
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>deg(n);
        for(int i=0;i<n;i++)
        {
            for(auto k:graph[i])
            {
                deg[i]++;
                adj[k].push_back(i);
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty())
        {
            int t = q.front(); q.pop();
            topo.push_back(t);
            for(auto i:adj[t])
            {
                deg[i]--;
                if(deg[i]==0)
                {
                    q.push(i);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};