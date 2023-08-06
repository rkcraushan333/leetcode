class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) 
    {
        stack<int>st;
        for(int i=v.size()-1;i>=0;i--)
        {
            st.push(v[i]);
        }
        vector<int>ans(v.size());
        for(int i=v.size()-1;i>=0;i--)
        {
            while(st.size()&&(st.top()<=v[i])) st.pop();
            if(st.size())
            {
                ans[i] = st.top();
            }
            else
            {
                ans[i] = -1;
            }
            st.push(v[i]);
        }
        return ans;
    }
};