class Solution {
public:
    vector<int>par,Size;
    int finds(int a){
        return par[a] = (a==par[a])?a:finds(par[a]);
    }
    void unions(int a,int b){
        a = finds(a);
        b = finds(b);
        if(a!=b){
            if(Size[a]>Size[b]) swap(a,b);
            par[b] = a;
            Size[a] += Size[b];
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        par.resize(n);
        Size.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
            Size[i] = 1;
        }
        for(auto v:edges){
            unions(v[0],v[1]);
        }
        long long res = 0;
        long long s = 0;
        for(int i=0;i<n;i++){
            if(par[i]==i){
                res += s*Size[i];
                s += Size[i];
            }
        }
        return res;
    }
};