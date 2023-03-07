#define ll long long
class Solution {
public:
    bool check(ll m,vector<int>&t,ll k){
        ll cnt = 0;
        for(auto &i:t){
            cnt += m/i;
            if(cnt>1e18) return true;
        }
        return cnt>=k;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll s = 0,e = 1e18;
        while(e-s>1){
            ll m = (s+e)/2;
            if(check(m,time,totalTrips)){
                e = m;
            }else{
                s = m;
            }
        }
        return e;
    }
};