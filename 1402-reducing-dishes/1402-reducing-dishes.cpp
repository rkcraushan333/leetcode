#define ll long long
class Solution {
public:
    int dp[501][501];
    ll f(vector<int>&v,int i=0,ll cnt =0){
        if(i==v.size()) return 0;
        int &t = dp[i][cnt];
        if(t!=-1) return t;
        ll res = 0;
        res = max(res,f(v,i+1,cnt));
        res = max(res,v[i]*(cnt+1)+f(v,i+1,cnt+1));
        return t=res;
    }
    int maxSatisfaction(vector<int>& s) {
        memset(dp,-1,sizeof(dp));
        sort(s.begin(),s.end());
        return f(s);
    }
};