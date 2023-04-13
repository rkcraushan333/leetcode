class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int j = 0;
        for(auto i:pushed){
            while(s.size()&&s.top()==popped[j]){
                s.pop();
                j++;
            }
            s.push(i);
            while(s.size()&&s.top()==popped[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};