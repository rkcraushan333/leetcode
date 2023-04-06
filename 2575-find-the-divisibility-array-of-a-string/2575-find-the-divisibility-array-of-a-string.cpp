class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>res;
        long long sum = 0;
        for(auto i:word){
            sum = sum*10+(i-'0');
            sum %= m;
            res.push_back(sum==0);
        }
        return res;
    }
};