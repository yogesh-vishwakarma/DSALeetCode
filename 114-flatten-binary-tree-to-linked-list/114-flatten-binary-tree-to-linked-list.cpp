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
    void flatten(TreeNode *root) {
        TreeNode* prev = NULL;
        flattenRec(root);
        // flattenIterative(root); // iteratively using stack
        // MorrisTraversal(root);
        
    }
    TreeNode * prev = NULL;
    void flattenRec(TreeNode * root) {
      if (root == NULL) 
          return;
      flattenRec(root -> right);
      flattenRec(root -> left);
      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }
    
   void flattenIterative(TreeNode * root) {
      if (root == NULL) 
          return;
      stack < TreeNode * > st;
      st.push(root);
      while (!st.empty()) {
        TreeNode * cur = st.top();
        st.pop();

        if (cur -> right != NULL) {
          st.push(cur -> right);
        }
        if (cur -> left != NULL) {
          st.push(cur -> left);
        }
        if (!st.empty()) {
          cur -> right = st.top();
        }
        cur -> left = NULL;
      }

    }
    
    void MorrisTraversal(TreeNode* root) {
        TreeNode* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				TreeNode* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }
    
};