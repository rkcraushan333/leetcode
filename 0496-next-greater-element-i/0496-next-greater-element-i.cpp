class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int>m;
        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]] = i;
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            int j = m[nums1[i]];
            while(j<nums2.size())
            {
                j++;
                if(j==nums2.size()) ans.push_back(-1);
                else if(nums2[j]>nums1[i]) 
                {
                    ans.push_back(nums2[j]); break;
                }
            }
        }
        return ans;
    }
};