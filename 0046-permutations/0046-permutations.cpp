class Solution {
public:
    vector<vector<int>>res;
    void f(vector<int>&nums,vector<int>&v,int mask=0)
    {
        if(mask==(1<<nums.size())-1) 
        {
            res.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mask&(1<<i)) continue;
            v.push_back(nums[i]);
            f(nums,v,mask|(1<<i));
            v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int>v;
        f(nums,v);
        return res;
    }
};