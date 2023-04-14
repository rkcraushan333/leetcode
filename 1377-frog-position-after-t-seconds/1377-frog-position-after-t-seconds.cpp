class Solution {
public:
    double dfs(int n,vector<vector<int>>&adj,int t,int target,int s,int par)
    {
        if(s==target && t==0)
            return 1;
        if(t<=0)
            return 0;
        
        double ans = 0.0;
        vector<int> x;
        for(auto i:adj[s])
        {
            if(i!=par)
                x.push_back(i);    
        }
        if(x.size()==0)
        {
           if(t>0 && s==target)
               return 1;
            else
                return 0;
        }
        for(auto tt:x)
        {
              ans+=dfs(n,adj,t-1,target,tt,s)/(double)(x.size());;
              
        }
       
        return ans;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        vector<vector<int>>adj(n+1);
        for(auto v:edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        return dfs(n,adj,t,target,1,-1);
    }
};