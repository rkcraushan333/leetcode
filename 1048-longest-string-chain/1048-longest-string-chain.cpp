class Solution {
public:
    static bool comp(string &s,string &t) 
    {
        return s.size()<t.size();
    }
    int dp[1001][1002];
    set<pair<int,int>>st;
    int f(vector<string>&v,int i=0,int j = -1)
    {
        if(i==v.size()) return 0;
        int &rkc = dp[i][j+1];
        if(rkc!=-1) return rkc;
        int ans = 0;
        ans = max(ans,f(v,i+1,j));
        if(j==-1)
        {
            ans = max(ans,1+f(v,i+1,i));
        }
        else
        {
            if(st.count({j,i}))
            {
                ans = max(ans,1+f(v,i+1,i));
            }
        }
        return rkc = ans;
    }
    int longestStrChain(vector<string>& words) 
    {
        int n = words.size();
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),comp);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string a = words[i],b = words[j];
            if(b.size()-a.size()==1)
            {
                int i1 = 0,i2 = 0,cnt = 0;
                while(i1<a.size()&&i2<b.size())
                {
                    if(a[i1]!=b[i2])
                    {
                        cnt++;
                        i2++;
                    }
                    else
                    {
                        i1++; i2++;
                    }
                }
                cnt += a.size()-i1;
                cnt += b.size()-i2;
                if(cnt==1)
                {
                    st.insert({i,j});
                }
            }
            }
        }
        // for(auto i:st){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        return f(words);
        // return 1;
    }
};