class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    vector<int>dj(int s,int n)
    {
        vector<int>dis(n,INT_MAX);
        dis[s] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,s});
        while(!pq.empty())
        {
            auto p = pq.top(); pq.pop();
            int node = p.second;
            int d = p.first;
            for(auto i:adj[node])
            {
                if(dis[i.first]>i.second+d)
                {
                    dis[i.first] = i.second+d;
                    pq.push({i.second+d,i.first});
                }
            }
        }
        return dis;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int dt)
    {
        adj.resize(n);
        for(auto i:edges)
        {
            adj[i[0]].push_back({i[1],i[2]});adj[i[1]].push_back({i[0],i[2]});
        }
        int ans,val=INT_MAX;
        for(int i=0;i<n;i++)
        {
            vector<int>v = dj(i,n);
            int curr = 0;
            for(int i=0;i<n;i++)
            {
                if(v[i]<=dt)
                {
                    curr++;
                }
            }
            if(val>curr)
            {
                val = curr;
                ans = i;
            }
            else if(val==curr)
            {
                ans = i; 
            }
        }
        return ans;
    }
};