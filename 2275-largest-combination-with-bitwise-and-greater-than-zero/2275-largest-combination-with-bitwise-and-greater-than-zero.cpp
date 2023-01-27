class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>v(32);
        for(auto i:candidates){
            int cnt = 0,curr=i;
            while(curr){
                if(curr&1) v[cnt]++;
                curr >>= 1;
                cnt++;
            }
        }
        int res =0;
        for(auto i:v){
            res = max(res,i);
        }
        return res;
    }
};