//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	string FirstNonRepeating(string &s)
	{
	    map<char,int>m;
	    queue<char>q;
	    for(auto &i:s)
	    {
	        m[i]++;
	        if(m[i]==1)
	        {
	            q.push(i);
	            while(m[q.front()]!=1)
	            {
	                q.pop();
	            }
	            i = q.front();
	        }
	        else
	        {
	            while(q.size()&&m[q.front()]>1)
	            {
	                q.pop();
	            }
	            if(q.empty()) i = '#';
	            else i=q.front();
	        }
	    }
	    return s;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends