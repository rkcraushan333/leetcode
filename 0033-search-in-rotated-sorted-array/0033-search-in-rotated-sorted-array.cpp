class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0,e = n-1;
        while(e>=s){
            int m = (s+e)>>1;
            if(target==nums[m])
                return m;
            else if(nums[m]>=nums[s]){
                if(target>=nums[s] && target<nums[m])
                    e = m-1;
                else 
                    s = m+1;
            }else{
                if(target>nums[m] && target<=nums[e])
                    s = m+1;
                else 
                    e = m-1;
            }
        }  
        return -1;
    }
};