class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<bool>vis(n);
        double res = 0;
        set<pair<double,int>>s;
        s.insert({0,start});
        while(s.size()){
            auto p = *s.rbegin();
            auto k = s.end();
            k--;
            s.erase(k);
            if(vis[p.second]) continue;
            vis[p.second] = 1;
            for(auto &t:adj[p.second]){
                int node = t.first;
                double wt = t.second;
                if(node==end){
                    if(p.first==0) res = max(res,wt);
                    else res = max(res,wt*p.first);
                }
                else{
                    if(p.first==0) s.insert({wt,node});
                    else s.insert({wt*p.first,node});
                }
            }
        }
        return res;
    }
};