class Solution {
public:
    vector<int>v;
    void f(TreeNode* root)
    {
        if(!root) return;
        f(root->left);
        v.push_back(root->val);
        f(root->right);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        f(root);
        return v[k-1];
    }
};