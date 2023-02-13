class Solution {
public:
    int countOdds(int a, int b) {
        if(a&1) return ((b-a)/2)+1;
        return (b-a+1)/2;
    }
};