class Solution {
public:
    vector<int>dis,vis;
    vector<pair<int,int>>adj[101];
    void f(int src){
        set<pair<int,int>>s;
        s.insert({0,src});
        dis[src] = 0;
        while(s.size()>0){
            auto node = *s.begin();
            s.erase(s.begin());
            if(vis[node.second]) continue;
            vis[node.second] = 1;
            for(auto& c:adj[node.second]){
                if(dis[c.first]>node.first+c.second){
                    dis[c.first] = node.first+c.second;
                    s.insert({dis[c.first],c.first});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dis.resize(n+1,INT_MAX);
        vis.resize(n+1);
        for(auto &v:times) adj[v[0]].push_back({v[1],v[2]});
        f(k);
        int res = 0;
        for(int i=1;i<=n;i++) {
            if(dis[i]==INT_MAX) return -1;
            res = max(res,dis[i]);
        }
        return res;
    }
};