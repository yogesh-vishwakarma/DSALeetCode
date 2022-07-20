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
    TreeNode* first; TreeNode* second;
    TreeNode* parent;
public:
    void recoverTree(TreeNode* root) {
        first = second = NULL;
        parent = new TreeNode(INT_MIN);
        
        inorderMod(root);
        
        swap(first->val, second->val);
    }
    
    void inorderMod(TreeNode * root){
        if(!root)
            return;
        inorderMod(root->left);
        if(parent && root->val < parent->val){
            if(!first){
                first = parent;
            }
            second = root;
        }
        parent = root;
        inorderMod(root->right);
    }
};