class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<vector<int>>adj(n);
        vector<int>deg(n);
        for(auto i:pre)
        {
            deg[i[0]]++;
            adj[i[1]].push_back(i[0]);
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
                if(deg[i]==0){
                    q.push(i);
                }
            }
        }
        return topo.size()==n;
    }
};