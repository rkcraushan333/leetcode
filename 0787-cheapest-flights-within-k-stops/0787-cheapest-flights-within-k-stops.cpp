class Solution {
public:
    #define ppi pair<int,pair<int,int>>
    vector<int> dj(vector<vector<pair<int,int>>>&adj,int src,int n,int k)
    {
        vector<int>v(n,INT_MAX);
        v[src] = 0;
        queue<ppi>pq;
        pq.push({0,{src,0}});
        while(!pq.empty())
        {
            auto t = pq.front(); pq.pop();
            int pr = t.first;
            int node = t.second.first;
            int k1 = t.second.second;
            if(k1>k) 
            {
                continue;
            }
            for(auto x:adj[node])
            {
                int nd = x.first,pr1 = x.second;
                if(v[nd]>pr1+pr)
                {
                    v[nd] = pr1+pr;
                    pq.push({pr1+pr,{nd,k1+1}});
                }
            }
        }
        return v;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto v:flights)
        {
            adj[v[0]].push_back({v[1],v[2]});
        }
        vector<int>v1 = dj(adj,src,n,k);
        // for(auto i:v1) cout<<i<<" ";
        return v1[dst]==INT_MAX?-1:v1[dst];
    }
};