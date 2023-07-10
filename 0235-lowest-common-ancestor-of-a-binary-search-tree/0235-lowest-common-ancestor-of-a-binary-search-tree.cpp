// O(logn) find the node where p and q lies on opposite side that will be my lca
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        int a = root->val;
        int b = p->val;
        int c = q->val;
        if(b>c) swap(b,c);
        if(b<=a&&c>=a)
        {
            return root;
        }
        else if(b>a)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else
        {
            return lowestCommonAncestor(root->left,p,q);
        }
    }
};