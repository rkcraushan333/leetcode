class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int>vis(32);
        for(auto i:nums){
            int cnt = 0,curr= i;
            while(curr){
                if(curr&1) vis[cnt] = 1;
                cnt++;
                curr >>= 1;
            }
        }
        int res = 0;
        for(int i=0;i<32;i++){
            if(vis[i]){
                res += (1<<i);
            }
        }
        return res;
    }
};