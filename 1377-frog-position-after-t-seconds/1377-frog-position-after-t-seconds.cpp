class Solution {
public:
    double fun(vector<vector<int>>&adj,int t,int target,int src,int par)
    {
        if(t==0) return src==target;
        if(src==target)
        {
            if(src==1) return  adj[src].size()==0;
            return adj[src].size()==1;
        }
        double ans = 0;
        for(int i=0;i<adj[src].size();i++)
        {
            int curr = adj[src][i];
            double prob;
            if(src==1) prob = (1.0/adj[src].size());
            else prob = (1.0/(adj[src].size()-1));
            if(par!=curr)
            {
                ans += prob*fun(adj,t-1,target,curr,src);
            }
        }
        return ans;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        double ans = fun(adj,t,target,1,-1);
        return ans;
    }
};