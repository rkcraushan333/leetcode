class Solution {
public:
    double f(double x,int n)
    {
        if(n==0) return 1;
        double k = f(x,n/2);
        if(n&1)
        {
            return k*k*x;
        }
        else
        {
            return k*k;
        }
    }
    double myPow(double x, int n) {
        if(n<0) return 1/f(x,n);
        return f(x,n);
    }
};