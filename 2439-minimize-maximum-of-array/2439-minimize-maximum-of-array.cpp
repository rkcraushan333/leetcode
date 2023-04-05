#define ll long long
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        ll s = nums[0],res = nums[0];
        for(int i=1;i<nums.size();i++){
            s += nums[i];
            if(nums[i]>res){
                res = max(res,(s+i)/(i+1));
            }
        }
        return res;
    }
};