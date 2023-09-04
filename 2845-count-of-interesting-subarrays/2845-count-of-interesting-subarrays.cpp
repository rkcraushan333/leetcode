// similar to xor subarray
class Solution {
public:
    #define ll long long
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k)
    {
        ll cnt = 0,ans = 0;
        unordered_map<int,int>m;
        m[cnt] = 1;
        for(auto i:nums)
        {
            cnt += ((i%mod)==k);
            cnt %= mod;
            ans += m[(cnt-k+mod)%mod];
            m[cnt]++;
        }
        return ans;
    }
};