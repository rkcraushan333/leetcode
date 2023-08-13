class Solution {
public:
    bool f(vector<int>&v,vector<int>&dp,int i=0)
    {
        if(i==v.size()) return 1;
        int &rkc = dp[i];
        if(rkc!=-1) return rkc;
        bool ans = 0;
        if(i<v.size()-1)
        {
            if(v[i]==v[i+1])
            {
                ans |= f(v,dp,i+2);
            }
        }
        if(i<v.size()-2)
        {
            if(v[i]==v[i+1]&&v[i+1]==v[i+2])
            {
                ans |= f(v,dp,i+3);
            }
            if(v[i+1]-v[i]==1&&v[i+2]-v[i]==2)
            {
                ans |= f(v,dp,i+3);
            }
        }
        return rkc = ans;
    }
    bool validPartition(vector<int>& nums) 
    {
        vector<int>dp(nums.size()+1,-1);
        return f(nums,dp);
    }
};