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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        /*Iteratively*/
        
        if(root==NULL){
		
            return ans;
        }
        
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
		
           TreeNode* top=stk.top();stk.pop();
            
            ans.push_back(top->val);
            if(top->right!=NULL){
                stk.push(top->right);
            }
            if(top->left!=NULL){
                stk.push(top->left);
            }
            
        }
        return ans; 
    }
};