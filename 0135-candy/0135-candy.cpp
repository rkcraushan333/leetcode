class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<pair<int,int>>v;
        for(int i=0;i<ratings.size();i++) v.push_back({ratings[i],i});
        sort(v.begin(),v.end());
        int res = 0;
        for(auto i:v){
            cout<<i.first<<" "<<i.second<<endl;
        }
        map<int,pair<int,int>>m;
        for(int i=0;i<v.size();i++){
            int a = v[i].second,b = v[i].first;
            if(m.find(a-1)==m.end()&&m.find(a+1)==m.end()){
                res++;
                m[a] = {1,b};
            }else if(m.find(a-1)!=m.end()&&m.find(a+1)==m.end()){
                if(m[a-1].second==b){
                    res++;
                    m[a] = {1,b};
                }
               else { res += m[a-1].first+1;
                m[a] = {m[a-1].first+1,b};}
            }else if(m.find(a-1)==m.end()&&m.find(a+1)!=m.end()){
                if(m[a+1].second==b){
                    res++;
                    m[a] = {1,b};
                }
               else {res += m[a+1].first+1;
                m[a] = {m[a+1].first+1,b};}
            }else{
                if(m[a-1].second==b&&m[a+1].second==b)
                {res++;
                    m[a] = {1,b};}
                else if(m[a-1].second==b) {
                    res += m[a+1].first+1;
                    m[a] = {m[a+1].first+1,b};
                }
                else if(m[a+1].second==b) {
                    res += m[a-1].first+1;
                    m[a] = {m[a-1].first+1,b};
                }
                else {res += max(m[a-1].first,m[a+1].first)+1;
                m[a] = {max(m[a-1].first,m[a+1].first)+1,b};}
            }
            cout<<res<<endl;
        }
        return res;
    }
};