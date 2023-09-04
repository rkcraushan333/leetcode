// similar to xor subarray
class Solution {
public:
    #define ll long long
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k)
    {
        ll cnt = 0,ans = 0;
        map<int,int>m;
        m[0] = 1;
        for(auto i:nums)
        {
            cnt += (i%mod)==k;
            cnt %= mod;
            if(cnt>=k)
            {
                int r = cnt-k;
                ans += m[r];
            }
            else 
            {
                int r = cnt-k+mod;
                ans += m[r];
            }
            m[cnt]++;
        }
        return ans;
    }
};