// Using Binary Search
class Solution {
public:
    #define ll long long
    ll f(int m,vector<int>&nums,vector<int>&cost)
    {
        ll ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            ans += abs(nums[i]-m)*1ll*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int s = INT_MAX;
        int e = INT_MIN;
        for(auto i:nums)
        {
            s = min(s,i); e = max(e,i);
        }
        ll ans = 2e18;
        while(s<=e)
        {
            int m = (s+e)>>1;
            ll curr = f(m,nums,cost);
            ll left = f(m-1,nums,cost);
            ll right = f(m+1,nums,cost);
            ans = min(ans,curr);
            if(curr>right) s = m+1;
            else if(curr>left) e = m-1;
            else return curr;
        }
        return ans;
    }
};