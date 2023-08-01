class Solution {
public:
    vector<vector<int>>res;
    void f(int n,int k,vector<int>&v,int i=1)
    {
        if(i==n+1)
        {
            if(v.size()==k) res.push_back(v);
            return;
        }
        f(n,k,v,i+1);
        v.push_back(i);
        f(n,k,v,i+1);
        v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>v;
        f(n,k,v);
        return res;
    }
};