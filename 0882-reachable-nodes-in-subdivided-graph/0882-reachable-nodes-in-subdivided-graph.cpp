class Solution {
public:
    vector<int> dj(vector<vector<pair<int,int>>>adj,int n)
    {
        vector<int>v(n,INT_MAX);
        v[0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto t = pq.top(); pq.pop();
            int node = t[1];
            int d = t[0];
            for(auto i:adj[node])
            {
                if(v[i.first]>i.second+d+1)
                {
                    v[i.first] = i.second+d+1;
                    pq.push({i.second+d+1,i.first});
                }
            }
        }
        return v;
    }
    int reachableNodes(vector<vector<int>>& edges, int mx, int n) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:edges)
      {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>v = dj(adj,n);
        // for(auto i:v) cout<<i<<" ";

        int ans = 0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=mx){
                ans++;
            }
        }
        for(auto i:edges)
        {
            int a = i[0],b = i[1];
            int d=i[2];
            int a1=max(0,(mx-v[a]));
            int b1=max(0,(mx-v[b]));
           // ans = max(ans,1+min(v[i[1]],i[2])+min(i[2],mx+max(0,mx-v[i[1]]));
           ans=ans+min(d,a1+b1);
        }
        return ans;
    }
};