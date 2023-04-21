class Solution {
public:
    vector<int> dsu,si;
    int find(int i)
    {
        if(i==dsu[i])return i;
        return dsu[i] = find(dsu[i]);
    }
    void f(int u ,int v)
    {
        int uu = find(u);
        int vv = find(v);
        if(uu==vv) return;
        if(si[uu]<si[vv])
        {
            dsu[uu] = vv;
            si[vv]+=si[uu];
        }
        else
        {
            dsu[vv] = uu;
            si[uu]+=si[vv];
        }
    }
    int largestComponentSize(vector<int>& nums) {
      int n = nums.size(),x=0;
        dsu.resize(1e6);
        si.resize(1e6,1);
        for(int i=0;i<1e6;i++)
        {
            dsu[i] = i;
        }
        unordered_set<int>s;
        for(auto it:nums)
        {
            s.insert(it);
            x = max(x,it);
        }
        for(int i=2;i<=x;i++)
        {
            int last =-1;
            for(int j=i;j<=x;j+=i)
            {
                if(s.find(j)!=s.end())
                {
                    if(last==-1)last = j;
                    else
                        {
                          f(last,j);
                          last  = j;
                         }
                }
            }
        }
        int res=0;
        for(auto it:si)
        {
          res = max(res,it);
        }
        return res;
      
    }
};