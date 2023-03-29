// iterative approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        if(!root) return v;
        stack<TreeNode*>s;
        TreeNode* node= root;
        while(true){
            if(node){
                s.push(node);
                node = node->left;
            }else{
                if(s.empty()) break;
                TreeNode *temp = s.top();
                s.pop();
                v.push_back(temp->val);
                node = temp->right;
            }
        }
        return v;
    }
};