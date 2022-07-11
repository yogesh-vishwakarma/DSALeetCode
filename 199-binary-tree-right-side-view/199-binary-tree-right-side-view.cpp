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
    void treeRightView(TreeNode *node, int currLevel, vector<int> &ans){
        if(!node)
            return;
        if(ans.size() == currLevel)
            ans.push_back(node->val);
        treeRightView(node->right,currLevel+1,ans);
        treeRightView(node->left,currLevel+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rView;
        
        /*BFS approach-- level order traversal*/
        if(!root) return {};
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = todo.front();
                todo.pop();
                if (i == n - 1) {
                    rView.push_back(node -> val);
                }
                if (node -> left) {
                    todo.push(node -> left);
                }
                if (node -> right) {
                    todo.push(node -> right);
                }
            }
        }
        
        /* DFS approach */
        // treeRightView(root,0,rView);
        
        return rView;
    }
};