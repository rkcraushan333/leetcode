class Solution {
public:
    #define ll long long
    int popcnt(ll n)
    {
        int curr=0;
        while(n)
        {
            if(n&1) curr++;
            n >>= 1;
        }
        return curr;
    }
    ll dp[61][1<<16];
    unordered_map<string,int>m;
    ll f(vector<vector<string>>&p,int n,int i=0,int mask=0)
    {
        if(mask==(1<<n)-1) return 0;
        if(i==p.size()) return INT_MAX;
        ll &rkc = dp[i][mask];
        if(rkc!=-1) return rkc;
        ll a = f(p,n,i+1,mask);
        int temp = mask;
        for(auto j:p[i])
        {
            temp |= (1<<m[j]);
        }
        ll b = f(p,n,i+1,temp);
        ll ans = 0;
        b |= (1LL<<i);
        if(popcnt(a)>popcnt(b))
        {
            ans = b;
        }
        else
        {
            ans = a;
        }
        return rkc = ans;
    }
    vector<int> smallestSufficientTeam(vector<string>& rs, vector<vector<string>>& people) {
        int n = rs.size();
        for(int i=0;i<n;i++)
        {
            m[rs[i]] = i;;
        }
        memset(dp,-1,sizeof(dp));
        ll ans = f(people,n);
        vector<int>v;
        for(int i=0;i<61;i++)
        {
            if(ans&(1LL<<i)) v.push_back(i);
        }
        return v;
    }
};