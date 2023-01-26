class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& bc, vector<double>& mf, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int x=0;x<bc.size();x++){
            adj[bc[x][0]].push_back({bc[x][1],mf[x]});
            adj[bc[x][1]].push_back({bc[x][0],mf[x]});
        }
        vector<bool>vis(n);
        double res = 0;
        set<pair<double,int>>s;
        s.insert({1,start});
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
                    res = max(res,wt*p.first);
                }
                else{
                    s.insert({wt*p.first,node});
                }
            }
        }
        return res;
    }
};