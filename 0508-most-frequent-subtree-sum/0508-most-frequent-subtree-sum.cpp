/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int>m;
    int f(TreeNode *root)
    {
        if(!root) 
        {
            return 0;
        }
        int sum = 0;
        sum += f(root->left);
        sum += f(root->right);
        sum += root->val;
        m[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        f(root);
        vector<int>v;
        int mx = 0;
        for(auto i:m)
        {
            mx = max(mx,i.second);
        }
        for(auto i:m)
        {
            if(mx==i.second)
            {
                v.push_back(i.first);
            }
        }
        return v;
    }
};