// Think like Dijkstra Alg
class Solution {
public:
    #define ppi pair<int,pair<int,int>>
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size(),m = nums2.size();
        vector<vector<int>>res;
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        set<pair<int,int>>st;
        int i = 0,j =0;
        pq.push({nums1[0]+nums2[0],{0,0}});
        st.insert({0,0});
        while((k--)&&pq.size())
        {
            auto t = pq.top();
            pq.pop();
            int a = t.second.first,b = t.second.second;
            res.push_back({nums1[a],nums2[b]});
            if((b+1<m) && (st.find({a,b+1})==st.end()))
            {
                pq.push({nums1[a]+nums2[b+1],{a,b+1}});
                st.insert({a,b+1});
            }
            if((a+1<n) && (st.find({a+1,b})==st.end()))
            {
                pq.push({nums1[a+1]+nums2[b],{a+1,b}});
                st.insert({a+1,b});
            }
        }
        return res;
    }
};