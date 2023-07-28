class Solution {
public:
    int dp[21][21];
    int f(vector<int>&v,int i,int j,bool b = 0)
    {
        if(i>j) return 0;
        int &t = dp[i][j];
        if(t!=-1) return t;
        int ans;
        if(!b)
        {
            ans = 0;
            ans = max(ans,v[i]+f(v,i+1,j,1));
            ans = max(ans,v[j]+f(v,i,j-1,1));
        }
        else
        {
            ans = 1e9;
            ans = min(ans,f(v,i+1,j,0));
            ans = min(ans,f(v,i,j-1,0));
        }
        return t = ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int s = accumulate(nums.begin(),nums.end(),0);
        int k = f(nums,0,nums.size()-1);
        cout<<k<<endl;
        return k>=(s+1)/2;
    }
};