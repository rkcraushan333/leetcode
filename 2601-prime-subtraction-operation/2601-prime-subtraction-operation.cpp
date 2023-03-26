class Solution {
public:
    bool prime[1001];
    vector<int>pm;
    void sieve(){
        memset(prime,1,sizeof(prime));
        prime[0] = prime[1] = 0;
        for(int i=2;i<1001;i++){
            if(prime[i]){
                for(int j=i+i;j<1001;j+=i) 
                    prime[j] = 0;
            }
        }
        for(int i=2;i<1001;i++){
            if(prime[i])
                pm.push_back(i);
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        sieve();
        int t = lower_bound(pm.begin(),pm.end(),nums[0])-pm.begin();
        if(t!=0){
            nums[0] -= pm[t-1];
        }
        cout<<nums[0]<<endl;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]) return 0;
            int cc = nums[i] - nums[i-1];
            t = lower_bound(pm.begin(),pm.end(),cc)-pm.begin();
            if(t!=0){
                nums[i] -= pm[t-1];
            }
        }
        return 1;
    }
};