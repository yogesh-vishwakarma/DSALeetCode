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
    void solve(TreeNode* root, string temp, vector<string> &ans) {
        if(root == NULL)
            return;
        
        if(root->left == NULL and root->right == NULL) {
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }
        
        temp += to_string(root->val);
        temp += "->";
        
        solve(root->left, temp,ans);
        solve(root->right, temp,ans);
        
        temp.pop_back(); 
        temp.pop_back(); 
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "",ans);
        return ans;
    }
};