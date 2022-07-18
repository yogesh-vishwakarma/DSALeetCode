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
    vector<int> inorderTraversal_interative(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>s;
        TreeNode* curr = root;
        
        while(curr != NULL || s.empty()==false)
        {
            while(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            
            v.push_back(curr->val);
            
            curr = curr->right;
        }
        return v;
    }
    
    vector<int> inorderTraversal(TreeNode* root){ // morrish traversal
        vector<int> ans;
        TreeNode *curr=root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr = curr->right; 
            }else{
                TreeNode *prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(!prev->right){
                    prev->right = curr;
                    curr = curr->left;
                }else{// prev->right pointing to curr node
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr-> right;
                }
                
            }
        }
        
        
        return ans;
    }
};