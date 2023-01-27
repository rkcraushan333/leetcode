class Solution {
public:
    unordered_set<string>hash;
    bool f(string w,int i=0,int cnt=0){
        if(cnt>=2 && i==w.size()){
            return true;
        }
        if(i==w.size()) return false;
        string t="";
        for(int j=i;j<w.size();j++){
            t += w[j];
            if(hash.find(t)!=hash.end()){
                if(f(w,j+1,cnt+1)) return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto &i:words) hash.insert(i);
        vector<string>res;
        for(auto i:words){
            if(f(i)) res.push_back(i);
        }
        return res;
    }
};