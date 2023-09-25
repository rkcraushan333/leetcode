//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    unordered_set<string>st;
	    vector<string>res;
	    void f(string s,int i=0)
	    {
	        if(i==s.size())
	        {
	            if(!st.count(s))
	            {
	                st.insert(s);
	                res.push_back(s);
	            }
	            return;
	        }
	       for(int j=i;j<s.size();j++)
	       {
	           swap(s[i],s[j]);
	           f(s,i+1);
	           swap(s[i],s[j]);
	       }
	    }
		vector<string>find_permutation(string s)
		{
		    f(s);
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends