class Solution {
public:
    int f(int n){
        int cnt = 0;
        while(n){
             cnt++;
            n=n&(n-1);
        }
        return cnt;
    }
    int minOperations(int n) {
        int res = f(n);
        for(int i=0;i<=200000;i++){
              res = min(res,f(n+i)+f(i));
        }
        return res;//101110
    }
};