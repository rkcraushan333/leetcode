class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans = 0;
        for(int j=0;j<32;j++)
        {
            int cnt = 0;
            int val = (1<<j);
            for(auto i:nums)
            {
                if(i&val)
                {
                    cnt++;
                }
            }
            if(cnt%3!=0)
            {
                ans |= (1<<j);
            }
        }
        return ans;
    }
};