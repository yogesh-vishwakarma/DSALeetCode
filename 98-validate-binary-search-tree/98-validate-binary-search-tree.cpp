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
     # define ll long long
    bool search(TreeNode* node,ll min, ll max){
        if(node==NULL){
            return true;
        }
        
        ll data = node->val;
        ll ldata=min,rdata=max;
        bool ls,rs;
        
        if(node->left!=NULL){
            ldata= node->left->val;
        }
        if(node->right!=NULL){
            rdata= node->right->val;
        }
        
        ls= search(node->left,min,data);
        rs= search(node->right,data,max);
        
        
        if(data>ldata && data<rdata && data>min && data < max){
            return(true && ls && rs);
        }
            
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        
      return search(root,-999999999999999,99999999999999);
    }
};