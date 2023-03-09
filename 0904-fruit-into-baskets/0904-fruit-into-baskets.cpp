class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>m;
        int res = 0,i=0,j =0,curr=0;
        while(j<fruits.size()){
            m[fruits[j]]++;
            curr++;
            while(m.size()>2){
                m[fruits[i]]--;
                if(!m[fruits[i]])
                    m.erase(fruits[i]);
                curr--;
                i++;
            }
            res = max(res,curr);
            j++;
        }
        return res;
    }
};