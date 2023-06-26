class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>len(n,1),cnt(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    int c = len[j]+1;
                    if(c==len[i])
                    {
                        cnt[i] += cnt[j];
                    }
                    else if(c>len[i])
                    {
                        len[i] = c;
                        cnt[i] = cnt[j]; 
                    }
                }
            }
        }
        int maxi=1;
        for(auto i:len)
        {
            maxi = max(maxi,i);
        }
        int ans = 0;
        for(auto i=0;i<n;i++)
        {
            if(maxi==len[i])
            {
                ans += cnt[i];
            }
        }
        return ans;
    }
};