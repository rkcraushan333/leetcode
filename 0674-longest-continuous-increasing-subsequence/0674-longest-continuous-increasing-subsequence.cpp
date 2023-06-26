class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int ans = 1,curr=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1]) 
            {
                curr++;
                ans = max(ans,curr);
            }
            else
            {
                curr = 1;
            }
        }
        return ans;
    }
};