class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0,e = nums.size();
        while(s<e){
            int mid = (s+e)>>1;
            if((mid!=0) && nums[mid]==nums[mid-1]){
                if((n-mid-1)%2==0) e = mid -1;
                else s = mid+1;
            }else if((mid!=n-1) && nums[mid]==nums[mid+1]){
                if((n-mid)%2==0) e = mid-1;
                else s = mid+1;
            }else
                return nums[mid];
        }
        return nums[s];
    }
};