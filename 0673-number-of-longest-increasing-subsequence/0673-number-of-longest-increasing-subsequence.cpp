// Time Complexity :- O(n^2)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<pair<int,int>>dp(n,{1,1});
        int mx = 1,ans = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(dp[i].first==dp[j].first+1)
                    {
                        dp[i].second += dp[j].second;
                    }
                    else if(dp[i].first<dp[j].first+1)
                    {
                        dp[i] = dp[j];
                        dp[i].first++;
                    }
                }
            }
            mx = max(mx,dp[i].first);
        }
        for(pair<int,int> &p:dp)
        {
            if(p.first==mx)
            {
                ans += p.second;
            }
        }
        return ans;
    }
};