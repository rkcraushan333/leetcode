//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    typedef long long ll;
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
       multiset<ll> ms;
       ll i=0,j=0,res=1e9;
       sort(a.begin(),a.end());
       while(j<n)
       {
           ms.insert(a[j]);
           if(j-i+1<m)
           j++;
           else if(j-i+1==m)
           {
               res=min(res,1LL*(*ms.rbegin()-*ms.begin()));
               ms.erase(ms.find(a[i]));
               i++;
               j++;
           }
       }
       return res;
    
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends