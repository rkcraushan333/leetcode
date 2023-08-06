//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string>ans;
    void f(string &s,int mask=0,string t="")
    {
        if(mask==(1<<s.size())-1) 
        {
            ans.push_back(t);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            if(mask&(1<<i)) continue;
            f(s,mask|(1<<i),t+s[i]);
        }
    }
    vector<string> permutation(string S)
    {
        f(S);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends