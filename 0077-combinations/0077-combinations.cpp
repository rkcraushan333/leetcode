class Solution {
public:
    vector<vector<int>>res;
    void f(int n,int k,int i,vector<int>&v){
        if(v.size()==k){
            res.push_back(v);
            return;
        }
        if(i==n+1) return;
        f(n,k,i+1,v);
        if(v.size()>0){
            if(i>v[v.size()-1])
            {
                v.push_back(i);
                f(n,k,i+1,v);
                v.pop_back();
            }
        }else{
            v.push_back(i);
            f(n,k,i+1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        f(n,k,1,v);
        return res;
    }
};