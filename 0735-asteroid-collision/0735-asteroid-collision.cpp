class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) 
    {
        stack<int>s;
        for(int i=0;i<v.size();i++)
        {
            if(s.empty()) s.push(v[i]);
            else
            {
                if(s.top()!=v[i])
                {
                    int curr = v[i];
                    while(s.size()&&curr&&(curr<0&&s.top()>0))
                    {
                        int a = s.top(); s.pop(); 
                        if(abs(a)>abs(v[i])) 
                        {
                            curr = a;
                        }
                        else if(abs(a)<abs(v[i]))
                        {
                            curr = v[i];
                        }
                        else 
                        {
                            curr = 0;
                        }
                    }
                    if(curr) s.push(curr);
                }
                else 
                {
                    s.push(v[i]);
                }
            }
        }
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top()); s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};