class Solution {
public:
    bool check(int target,int m,vector<int>& v){
        int i = 0,j = 0,s = 0;
        while(j<v.size()){
            s+= v[j];
            if(j-i+1==m){
                if(s>=target) return true;
                s -= v[i];
                i++;
            }
            j++;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = -1,e = nums.size()+1;
        while(e-s>1){
            int m = (s+e)>>1;
            if(check(target,m,nums))
                e = m;
            else 
                s = m;
        }
        return e==nums.size()+1?0:e;
    }
};