class Solution {
public:
    vector<int> par;
    vector<int> Size;
    void make_Set(int v)
    {
        par[v] = v;
        Size[v] = 1;
    }
    int find_Set(int v)
    {
        return par[v] = (par[v] == v) ? v : find_Set(par[v]);
    }
    void union_Set(int u, int v)
    {
        u = find_Set(u);
        v = find_Set(v);
        if (u != v){
            if(Size[u]<Size[v]) swap(u,v);
            par[v] = u;
            Size[u] += Size[v];}
    }
    int largestComponentSize(vector<int>& nums) {
        par.resize(1e6);
        Size.resize(1e6);
        for(int i=0;i<1e6;i++) make_Set(i);
        unordered_set<int>s;
        int n = 0;
        for(int i=0;i<nums.size();i++){ s.insert(nums[i]); n = max(n,nums[i]);}
        for(int i=2;i<=n;i++){
            int last = -1;
            for(int j = i;j<=n;j+=i){
                if(s.find(j)!=s.end()){
                    if(last==-1) last = j;
                    else{
                        union_Set(last,j);
                        last = j;
                    }
                }
            }
        }
        int res = 0;
        for(auto i:Size){
            res = max(i,res);
        }
        return res;
    }
};