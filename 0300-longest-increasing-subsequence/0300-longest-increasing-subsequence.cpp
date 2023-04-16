class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        for(auto i:nums){
            int t = lower_bound(v.begin(),v.end(),i)-v.begin();
            if(t==v.size())
                v.push_back(i);
            else
                v[t] = i;
        }
        return v.size();
    }
};