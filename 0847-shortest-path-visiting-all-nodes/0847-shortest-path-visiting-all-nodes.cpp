class Solution {
public:
    int dp[13][1<<12];
    int f(vector<vector<int>>&adj,vector<vector<int>>&dis,int s,int mask)
    {
        int n = adj.size();
        if(mask==(1<<n)-1)
            return 0;
        int &rkc = dp[s][mask];
        if(rkc!=-1) return rkc;
        int ans = 1e9;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i)) continue;
            ans = min(ans,dis[s][i]+f(adj,dis,i,mask|(1<<i)));
        }
        return rkc = ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
        {
            for(auto j:graph[i])
            {
                adj[i].push_back(j);
                dis[i][j] = 1;
                dis[j][i] = 1;
            }
            dis[i][i] = 0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
        
        int ans = 1e9;
        for(int i=0;i<n;i++)
        {
            memset(dp,-1,sizeof(dp));
            int mask = (1<<i);
            ans = min(ans,f(adj,dis,i,mask));
        }
        return ans;
    }
};