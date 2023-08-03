class Solution {
public:
    map<char,string>m;
    vector<string>res;
    void f(string &s,string &t,int i=0)
    {
        if(i==s.size())
        {
            if(t.size()) res.push_back(t);
            return;
        }
        string st = m[s[i]];
        for(int k=0;k<st.size();k++)
        {
            t.push_back(st[k]);
            f(s,t,i+1);
            t.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        char c = 'a';
        for(char i='2';i<='9';i++)
        {
            string s;
            s += c++; s += c++; s += c++;
            if(i=='7'||i=='9') s += c++;
            m[i] = s;
        }
        string t="";
        f(digits,t);
        return res;
    }
};