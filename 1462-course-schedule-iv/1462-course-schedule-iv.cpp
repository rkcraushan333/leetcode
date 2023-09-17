// Toposort Best way
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>&p, vector<vector<int>>&q) 
    {
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for(int i=0;i<p.size();i++)
        {
            adj[p[i][0]].push_back(p[i][1]);
            indeg[p[i][1]]++;
        }
        set<int>st[n];
        queue<int>q1;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0) q1.push(i);
        }
        while(q1.size())
        {
            int t = q1.front(); q1.pop();
            for(auto child:adj[t])
            {
                st[child].insert(t);
                for(auto i:st[t])
                {
                     st[child].insert(i);
                 }
                indeg[child]--;
                if(indeg[child]==0)
                {
                    q1.push(child);
                }
            }
        }
        vector<bool>ans;
        for(int i=0;i<q.size();i++)
        {
            ans.push_back(st[q[i][1]].count(q[i][0]));
        }
        return ans;
    }
};