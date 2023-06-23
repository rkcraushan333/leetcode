class Solution {
public:
    unordered_set<string>hash;
    vector<string>ans;
    void f(string &s,int i=0,string t="")
    {
        if(i==s.size())
        {
            ans.push_back(t);
            return;
        }
        string curr = "";
        for(int j=i;j<s.size();j++)
        {
            curr += s[j];
            if(hash.find(curr)!=hash.end())
            {
                if(j<s.size()-1)
                {
                    f(s,j+1,t+curr+" ");
                }
                else
                {
                    f(s,j+1,t+curr);
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        for(auto i:wordDict)
        {
            hash.insert(i);
        }
        f(s);
        return ans;
    }
};