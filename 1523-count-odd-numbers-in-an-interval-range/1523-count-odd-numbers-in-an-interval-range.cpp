class Solution {
public:
    int countOdds(int a, int b) {
        return (a&1)?((b-a)/2)+1:(b-a+1)/2;
    }
};