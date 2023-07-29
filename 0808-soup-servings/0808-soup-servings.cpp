class Solution {
public:
    map<pair<int,int>,double>m;
    double f(int a,int b)
    {
        if(a<=0) 
        {
            if(b<=0) return 0.5;
            return 1;
        }
        if(b<=0) return 0;
        if(m.count({a,b}))
        {
            return m[{a,b}];
        }
        double ans = 0;
        ans += f(a-100,b)/4.0;
        ans += f(a-75,b-25)/4.0;
        ans += f(a-50,b-50)/4.0;
        ans += f(a-25,b-75)/4.0;
        return m[{a,b}] = ans;
    }
    double soupServings(int n) 
    {
        if(n>4800) return 1;
        return f(n,n);
    }
};