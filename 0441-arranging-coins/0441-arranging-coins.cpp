class Solution {
public:
    bool check(int m,int n){
        long long k = m;
        k = (k*(k+1))/2;
        return n>=k;
    }
    int arrangeCoins(int n) {
        int l = 0, r = 1e9;
        while(r-l>1){
            int m = (r+l)/2;
            if(check(m,n))
                l = m;
            else 
                r=m;
        }
        return l;
    }
};