// Using DSU
class Solution {
public:
    vector<int>par,Size;
    int finds(int a)
    {
        return par[a] = (a==par[a]?a:finds(par[a]));
    }
    void unions(int a,int b)
    {
        a = finds(a);
        b = finds(b);
        if(a!=b)
        {
            if(Size[a]>Size[b]) swap(a,b);
            Size[a] += Size[b];
            par[b] = a;
        }
    }
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        int n = nums.size();
        par.resize(n);
        Size.resize(n,1);
        for(int i=0;i<n;i++) par[i] = i;
        for(int i=0;i<n;i++)
        {
            int curr = nums[i];
            // Here we will not include those no which allreay been used
            if(mp.count(curr)) continue;
            if(mp.count(curr-1)) unions(i,mp[curr-1]);
            if(mp.count(curr+1)) unions(i,mp[curr+1]);
            mp[curr] = i;
        }
        int ans = 0;
        for(int i=0;i<n;i++) ans = max(ans,Size[i]);
        return ans;
    }
};