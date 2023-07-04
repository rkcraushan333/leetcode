class Solution {
public:
    // count each bit 
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int j=0;j<32;j++)
        {
            int cnt = 0;
            for(auto i:nums)
            {
                if(i&(1<<j)) cnt++;
            }
            if(cnt%3) ans |= 1<<j;
        }
        return ans;
    }
};