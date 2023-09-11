class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        vector<vector<int>>ans;
        map<int,vector<int>>m;
        for(int i=0;i<groupSizes.size();i++)
        {
            m[groupSizes[i]].push_back(i);
        }
        for(auto i:m)
        {
            int k = i.second.size()/i.first;
            int i1=0;
            for(int j=0;j<k;j++)
            {
                vector<int>v;
                for(int i1=0;i1<i.first;i1++)
                {
                    v.push_back(i.second[i1]);
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};