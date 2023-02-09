class Solution {
public:
    typedef long long ll;
    typedef string str;
    long long distinctNames(vector<string>& ideas)
    {
        map<char,set<str>> mp;
        for(auto t: ideas)
        {
            mp[t[0]].insert(t.substr(1));
        }
        ll ans=0;
        for(ll i=0;i<26;i++)
        {  set<str> sex=mp[i+'a'];
            for(ll j=i+1;j<26;j++)
            {
                set<str> st=mp[(j+'a')];
                ll temp=0;
                for(auto it=st.begin();it!=st.end();it++)
                {
                    if(sex.find(*it)!=sex.end())
                        ++temp;
                }
                ans+=(sex.size()-temp)*(st.size()-temp);
                
            }
        }
        return ans*2LL;
        
    }
};