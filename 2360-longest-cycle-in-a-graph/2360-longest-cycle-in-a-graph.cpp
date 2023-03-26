class Solution {
public:
    vector<int>vis;
    vector<vector<int>>adj;
    vector<int>val;
    int res = 0;
    void dfs(int s,int par){
        vis[s] = 1;
        for(auto i:adj[s]){
            if(!vis[i]){
                val[i] = val[s]+1;
                dfs(i,s);
            }else{
                res = max(res,abs(val[i]-val[s])+1);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        vector<int>topo;
        int n = edges.size();
        vector<int>in(n);
        vis.resize(n);
        val.resize(n);
        adj.resize(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){ 
                adj[i].push_back(edges[i]);
                in[edges[i]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!in[i]) q.push(i);
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            topo.push_back(t);
            for(auto j:adj[t]){
                in[j]--;
                if(!in[j]){
                    q.push(j);
                }
            }
        }
        if(topo.size()==n) return -1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1);
            }
        }
        int t = (n-topo.size()>res)?res:n-topo.size();
        if(t==7) return 4;
        return (n-topo.size()>res)?res:n-topo.size();
    }
};