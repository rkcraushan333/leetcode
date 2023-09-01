class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int>v;
        v.push_back(0);
        for(int i=1;i<=n;i++)
        {
            int ans = v[i/2];
            if(i&1) ans++;
            v.push_back(ans);
        }
        return v;
    }
};