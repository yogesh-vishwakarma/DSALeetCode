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
 int max_height(TreeNode* root)
 {
     if(root == NULL)
     {
        return 0;
     }
     int l = max_height(root->left);
     int r = max_height(root->right);
     return max(l, r) + 1;
 }
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return max_height(root);
    }
};