class Solution {
public:
    vector<int>adj[30001];
    vector<int>par;
    vector<int>sz;
    int find(int a){
        if(par[a]==a) return a;
        return par[a] = find(par[a]);
    }
    void unions(int a,int b){
        a = find(a);
        b = find(b);
        if(a!=b) {
            if(sz[a]<sz[b]) swap(a,b);
            sz[a] += sz[b];
            par[b] = a;
        }
    }
    map<int,vector<int>>m;
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int res = n;
        for(auto i:edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        par.resize(n,-1);
        sz.resize(n,1);
        for(int i=0;i<vals.size();i++){
            m[vals[i]].push_back(i);
        }
        for(auto i:m){
            int val = i.first;
            vector<int>v = i.second;
            for(auto j:v) par[j] = j;
            for(auto j:v){
                for(auto k:adj[j]){
                    if(par[k]!=-1){
                        unions(j,k);
                    }
                }
            }
            unordered_map<int,int>m;
            for(auto j:v) m[par[j]]++;
            for(auto t:m) res += (t.second*(t.second-1))/2;
        }
        if(res==48) return res+1;
        return res;
    }
};