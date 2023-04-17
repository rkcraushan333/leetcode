class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ex) {
        int mx = candies[0];
        for(auto i:candies) mx = max(mx,i);
        vector<bool>res;
        for(auto i:candies){
            if(i+ex>=mx) res.push_back(1);
            else res.push_back(0);
        }
        return res;
    }
};