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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)
            return root1;
        else if(root1 && root2){
            root1->val = root1->val + root2->val;
        }
        else if(!root1 && root2){
            root1 = new TreeNode((root2->val));
        }
        else if(root1 && !root2){
            root2 = new TreeNode();
        }
//         root1->left = (root1 && root1->left)? root1->left : NULL;
//         root1->right = (root1->right)? root1->right : NULL;
        
//         root2->left = (root2->left)? root2->left : NULL;
//         root2->right = (root2->right)? root2->right : NULL;
        
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);  
        return root1;
    };
    
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
//     }
};