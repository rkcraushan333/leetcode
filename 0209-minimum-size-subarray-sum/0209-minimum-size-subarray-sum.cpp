class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int i = 0, j = 0,s = 0;
        while(j<nums.size()){
            s += nums[j];
            while(s>=target){
                res = min(res,j-i+1);
                s -= nums[i];
                i++;
            }
            j++;
        }
        return res==INT_MAX?0:res;
    }
};