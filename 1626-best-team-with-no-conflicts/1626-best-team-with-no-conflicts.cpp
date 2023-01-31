class Solution {
public:
    vector<pair<int,int>>v;
    int dp[1001][1001];
    int f(int i,int maxi=0){
        if(i<0) return 0;
        if(dp[i][maxi]!=-1) return dp[i][maxi];
        int a = f(i-1,maxi);
        int b = INT_MIN;
        if(maxi==0||v[i].second<=maxi) {b = v[i].first+f(i-1,v[i].second);}
        return dp[i][maxi] = max(a,b);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        for(int i=0;i<n;i++){
            v.push_back({scores[i],ages[i]});
        }
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return f(n-1);
    }
};