class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        if(!root) return v;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            v.push_back(node->val);
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};