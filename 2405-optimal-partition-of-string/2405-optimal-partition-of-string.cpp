class Solution {
public:
    int partitionString(string s) {
        int cnt = 1;
        unordered_set<int>m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end()){
                while(m.size()){
                    m.erase(m.begin());
                }
                m.insert(s[i]);
                cnt++;
            }
            m.insert(s[i]);
        }
        return cnt;
    }
};