class Solution {
public:
    int reductionOperations(vector<int>& nums){
        sort(nums.rbegin(),nums.rend());
        int n = nums.size();
        int res = 0,cnt =1,prev = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==prev)
                continue;
            else{
                res += i;
                prev = nums[i];
            }
            // cout<<res<<endl;
            if(nums[i]==nums[n-1]) break;
        }
        return res;
    }
}; 