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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans(0);
        diameterBT(root, ans);
        return ans;
    }
    int diameterBT(TreeNode *root, int &ans){
        if(!root)
            return 0;
        int lside = diameterBT(root->left, ans);
        int rside = diameterBT(root->right, ans);
        ans = max(ans,lside+rside);
        return max(lside,rside) +1 ;
    }
};