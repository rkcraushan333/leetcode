class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>v;
        for(auto i:nums1) v.push_back(i);
        for(auto i:nums2) v.push_back(i);
        sort(v.begin(),v.end());
        int n = v.size();
        if(n&1) return v[n/2];
        double a = v[n/2-1],b = v[n/2];
        return (a+b)/2;
    }
};