class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i=0;i<30;i++){
            if(((a|b)&1)!=(c&1)) { 
                cnt++;
                if((a&1)&(b&1)) cnt++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};