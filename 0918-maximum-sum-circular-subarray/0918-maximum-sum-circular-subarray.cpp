// use kadane's algorithm to find the min_sum and max_sum
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_res = nums[0],max_res = nums[0],min_sum = 0,max_sum = 0, sum = 0;
        for(auto &i:nums){
            min_sum += i;
            max_sum += i;
            sum += i;
            min_res = min(min_res,min_sum);
            max_res = max(max_res,max_sum);
            if(min_sum>0) min_sum = 0;
            if(max_sum<0) max_sum = 0;
        }
        if(min_res==sum) return max_res;
        return max(max_res,sum-min_res);
    }
};