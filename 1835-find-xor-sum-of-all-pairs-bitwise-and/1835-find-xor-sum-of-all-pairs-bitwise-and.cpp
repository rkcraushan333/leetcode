class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        for(int i=1;i<arr1.size();i++){
            arr1[0] ^= arr1[i];
        }
        for(int i=1;i<arr2.size();i++){
            arr2[0] ^= arr2[i];
        }
        return arr2[0]&arr1[0];
    }
};