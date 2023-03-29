// Using 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        if(!root) return v;
        TreeNode* curr = root;
        stack<TreeNode*>s;
        while((curr!=NULL)||(!s.empty())){
            if(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            }else{
                TreeNode* temp;
                temp = s.top()->right;
                if(!temp){
                    temp = s.top();
                    s.pop();
                    v.push_back(temp->val);
                    while((!s.empty())&& temp==s.top()->right){
                        temp = s.top();
                        s.pop();
                        v.push_back(temp->val);
                    }
                }else
                    curr = temp;
            }
        }
        return v;
    }
};