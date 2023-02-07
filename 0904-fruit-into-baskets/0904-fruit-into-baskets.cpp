class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>s;
        int i = 0,j=0,res=0;
        while(j<fruits.size()){
            s[fruits[j]]++;
            while(s.size()>2){
                if(s[fruits[i]]==1) s.erase(fruits[i]);
                else s[fruits[i]]--;
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};