class Solution {
public:
    bool check(vector<int>&w,int d,int m){
        int cnt = 1,s=0;
        for(auto i:w){
            if(i>m) return false;
            s += i;
            if(s>m){
                s = i;
                cnt++;
            }
        }
        return cnt<=d;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int s = 0, e = 1e8;
        while(e-s>1){
            int m = (s+e)/2;
            if(check(w,d,m))
                e = m;
            else
                s = m;
        }
        return e;
    }
};