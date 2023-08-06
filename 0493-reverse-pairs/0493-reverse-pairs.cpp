#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<long, null_type, less_equal<long>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)

class Solution {
public:
    int reversePairs(vector<int>& nums) 
    {
        T.clear();
        long ans = 0;
        for(long i:nums)
        {
            long k = T.order_of_key(2*i+1);
            ans += (T.size()-k);
            T.insert(i);
        }
        return ans;
    }
};