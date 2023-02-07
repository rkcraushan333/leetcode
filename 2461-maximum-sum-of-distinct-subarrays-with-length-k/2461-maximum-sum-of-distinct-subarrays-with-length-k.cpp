class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        long long res=0,sum=0;
        map<int,int>m;
        while(j<nums.size()){
            sum += nums[j];
            m[nums[j]]++;
            if(j-i+1<k){
                j++;
                continue;
            }
            if(j-i+1==k && m.size()==k){
                res = max(res,sum);
            }
            sum -= nums[i];
            m[nums[i]]--;
            if(!m[nums[i]])
                m.erase(nums[i]);
            i++;
            j++;
        }
        return res;
    }
};