class Solution {
public:
    vector<int> dj(int n,vector<vector<pair<int,int>>>&adj,int k)
    {
        vector<int>v(n,INT_MAX);
        v[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(pq.size())
        {
            auto t = pq.top(); pq.pop();
            int d = t.first;
            int node = t.second;
            for(auto i:adj[node])
            {
                // cout<<"debug";
                int a = i.first, b = i.second;
                if(v[a]>d+b)
                {
                    // cout<<"debug";
                    v[a] = d+b;
                    pq.push({d+b,a});
                }
            }
        }
        return v;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto v:times)
        {
            adj[v[0]-1].push_back({v[1]-1,v[2]});
        }
        vector<int>v1 = dj(n,adj,k-1);
        int mx = 0;
        for(auto i:v1)
        {
            // cout<<i<<endl;
            mx = max(mx,i);
        }
        return mx==INT_MAX?-1:mx;
    }
};