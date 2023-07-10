class Solution {
public:
    void f(TreeNode* root,int val)
    {
        if(root->val>val)
        {
            if(!root->left)
            {
                root->left = new TreeNode(val);
                return;
            }
            else
            {
                f(root->left,val);
            }
        }
        else
        {
            if(!root->right)
            {
                root->right = new TreeNode(val);
                return;
            }
            else
            {
                f(root->right,val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(!root)
        {
            root = new TreeNode(val);
            return root;
        }
        f(root,val);
        return root;
    }
};