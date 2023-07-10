class Solution {
public:
    // inorder of a bst is always sorted
    int cnt,ans;
    void f(TreeNode* root,int k)
    {
        if(!root) return;
        f(root->left,k);
        cnt++;
        if(cnt==k)
        {
            ans = root->val;
            return;
        }
        f(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        f(root,k);
        return ans;
    }
};