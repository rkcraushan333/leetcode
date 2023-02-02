#define ll long long
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        ll res = 1,i=0,j=0,last=0;
        while(j<nums.size()){
            if((last&nums[j])!=0){
                while(((last&nums[j])!=0) && (i<j)){
                    last ^= nums[i];
                    i++;
                }
            }
            last |= nums[j];
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};