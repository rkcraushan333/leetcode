// using prefix sum
class Solution {
public:
    #define ll long long
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        vector<pair<ll,ll>>v;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        ll ans = 0;
        // finding ans for the 1st index
        for(int i=1;i<n;i++)
        {
            ans += (v[i].first-v[0].first)*v[i].second;
        }
        
        // prefix sum of cost 
        for(int i=1;i<n;i++)
        {
            v[i].second += v[i-1].second;
        }
        
        // minimizing the ans
        for(int i=1;i<n;i++)
        {
            ll dif = v[i].first - v[i-1].first;
            ll left = (v[i-1].second)*dif;
            ll right = (v[n-1].second-v[i-1].second)*dif;
            ans = min(ans,ans+left-right);
        }
        return ans;
    }
};