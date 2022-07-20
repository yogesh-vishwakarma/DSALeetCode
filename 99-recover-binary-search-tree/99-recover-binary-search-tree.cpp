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
    TreeNode* first;
    TreeNode* parent;
    TreeNode* middle;
    TreeNode* last;
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        parent = new TreeNode(INT_MIN);
        
        inorderMod(root);
        
        if(first && last)
            swap(first->val, last->val);
        // else if(first && middle)
        //     swap(first->val, middle->val);        
    }
    
    void inorderMod(TreeNode * root){
        if(!root)
            return;
        inorderMod(root->left);
        if(parent && root->val < parent->val){
            if(!first){
                first = parent;
                last = root;
            }
            else{
                last = root;
            }
        }
        parent = root;
        inorderMod(root->right);
    }
};