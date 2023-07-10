// Topo Sort
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) 
    {
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for(auto i:v)
        {
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        while(q.size()>0)
        {
            int t = q.front(); q.pop();
            topo.push_back(t);
            for(auto c:adj[t])
            {
                indeg[c]--;
                if(indeg[c]==0)
                {
                    q.push(c);
                }
            }
        }
        return topo.size()==n;
    }
};