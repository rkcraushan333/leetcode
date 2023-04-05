// All in one
// concept :- preorder(1) ++ left
//            inorder(2) ++ right
//            postorder(3)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<pair<TreeNode*,int>>s;
        s.push({root,1});
        vector<int>preorder,inorder,postorder;
        while(s.size()){
            auto p = s.top();
            s.pop();
            if(p.second==1){
                preorder.push_back(p.first->val);
                p.second++;
                s.push(p);
                if(p.first->left!=NULL) s.push({p.first->left,1});
            }else if(p.second==2){
                inorder.push_back(p.first->val);
                p.second++;
                s.push(p);
                if(p.first->right!=NULL) s.push({p.first->right,1});
            }else{
                postorder.push_back(p.first->val);
            }
        }
        return postorder;
    }
};