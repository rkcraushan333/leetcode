class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        map<int,int>m;
        for(auto i:p) m[i]++;
        int res = 0;
        while(m.size()){
            auto t = m.end();
            t--;
            if((t->first)>=limit){
                res += t->second;
                m.erase(t);
                continue;
            }
            res++;
            int k = t->first;
            m[t->first]--;
            if(m[t->first]==0){
                m.erase(t);
            }
            if(m.size()==0) break;
            auto f = m.lower_bound(limit-k);
            if(f==m.end()){
                f--;
            m[f->first]--;
            if(m[f->first]==0)
            {
                m.erase(f);
            }
        }else{
                if(f->first==limit-k){
                    m[f->first]--;
            if(m[f->first]==0)
            {
                m.erase(f);
            }
            }
            else{
                if(f==m.begin()){
                }else{
                    f--;
                    m[f->first]--;
                   if(m[f->first]==0)
                   {
                      m.erase(f);
                   }
                }
                }
            }
    }
        return res;
    }
};