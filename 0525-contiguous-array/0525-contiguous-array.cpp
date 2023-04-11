class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(auto &i:nums) if(!i) i = -1;
        int s = 0,res = 0;
        map<int,int>m;
        m[0] = -1;
        for(int i=0;i<nums.size();i++){
            s += nums[i];
            // cout<<res<<endl;
            if(m.find(s)==m.end()) m[s] = i;
            else res = max(res,i-m[s]);
        }
        return res;
    }
};