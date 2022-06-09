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
    
    // we are using a dfs helper function
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfsHelper(root,res);
        return res;
    }
    
    int dfsHelper(TreeNode* root, int &res){
        int left(0),right(0);
        
        // base condition
        if(root == NULL)
            return 0;
        // max path in left subtree
        left = max(left, dfsHelper(root->left, res));
        
        // max path in right subtree
        right = max(right,dfsHelper(root->right, res));
        
        /* res would be max of res and new res 
        which is sum of max paths in left & right subtree & root node */
        
        res = max(res, left+right+root->val);
        
        // return curr max sum path which is sum of max paths in left & right subtree & root node 
        return max(left , right) + root->val;
    }
};