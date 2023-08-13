int maxN;
vector<int>p;
    void sieve()
    {
        for(long long i=2;i<maxN;i++)
        {
           if(p[i]==1)
           {
               for(long long j=i*i;j<maxN;j+=i)
                   p[j]=0;
           }
        }
    }
class Solution {
public:   
    int countPrimes(int n) 
    {
        p.resize(n+1,1);
        maxN = n+1;
        int cc=0;
        sieve();
        for(int i=2;i<n;i++)
        {
             if(p[i])++cc;
        }
        return cc;
    }
};