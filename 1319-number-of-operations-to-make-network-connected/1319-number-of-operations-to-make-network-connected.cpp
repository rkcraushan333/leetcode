class Solution {
public:
    vector<int>par;
    vector<int>sz;
    int res=0,components;
    void makeSet(int a) {
        par[a] = a;
        sz[a] = 1;
    }
    int findSet(int a){
        if(par[a] == a) 
            return a;
        return par[a] = findSet(par[a]);
    }
    void unionSet(int a,int b){
        a = findSet(a);
        b = findSet(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            par[b] = a;
            sz[a] += sz[b];
            components--;
        }
        else
            res++;              
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        par.resize(n);
        sz.resize(n);
        components = n;
        for(int i=0;i<n;i++) 
            makeSet(i);
        
        for(int i=0;i<connections.size();i++)
            unionSet(connections[i][0],connections[i][1]);
 
         if(components-1>res) return -1;
        return min(res,components-1);
    }
};