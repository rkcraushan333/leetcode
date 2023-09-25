class Solution {
public:
    vector<vector<int>>res;
    void f(vector<int>&nums,vector<int>&v,vector<int>&vis)
    {
        if(v.size()==nums.size()) 
        {
            res.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]==0)
            {
                vis[i] = 1;
                v.push_back(nums[i]);
                f(nums,v,vis);
                v.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>v,vis(n);
        int cnt = 0;
        f(nums,v,vis);
        return res;
    }
};