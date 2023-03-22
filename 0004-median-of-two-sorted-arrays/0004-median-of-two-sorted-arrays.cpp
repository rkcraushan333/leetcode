class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        // so that binary search will be done on smaller size array
        int n1 = nums1.size(), n2 = nums2.size();
        int lo = 0, hi = n1;
        while(lo<=hi){
            int cut1 = (lo+hi)>>1;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1==0?INT_MIN:nums1[cut1-1];
            int left2 = cut2==0?INT_MIN:nums2[cut2-1];
            
            int right1 = cut1==n1?INT_MAX:nums1[cut1];
            int right2 = cut2==n2?INT_MAX:nums2[cut2];
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2==0){
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }else
                    return max(left1,left2);
            }
            else if(left1>right2){
                hi = cut1-1;
            }else
                lo = cut1+1;
        }
        return 0.0;
    }
};