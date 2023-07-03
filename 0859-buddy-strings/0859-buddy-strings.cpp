class Solution {
public:
    bool buddyStrings(string s, string t)
    {
        if(s.size()!=t.size()) return 0;
        string a = s,b = t;
        sort(a.begin(),a.end()); sort(b.begin(),b.end());
        if(a!=b) return 0;
        int n = s.size(),cnt = 0;
        vector<int>v(26);
        bool ob = 0;
        for(int i=0;i<n;i++) 
        {
            if(s[i]!=t[i]) cnt++;
            else v[s[i]-'a']++;
            if(v[s[i]-'a']==2) ob = 1;
        }
        if(cnt==0 && ob) return 1;
        if(cnt==2) return 1;
        return 0;
    }
};