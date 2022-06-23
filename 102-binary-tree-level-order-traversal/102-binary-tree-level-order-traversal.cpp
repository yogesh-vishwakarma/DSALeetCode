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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        // bfs
        queue<TreeNode*> qt;
        qt.push(root);
        while (!qt.empty())
        {
            int n = qt.size();
            vector<int> vt;
            for (int i = 0; i < n; ++i)
            {
                auto t = qt.front(); qt.pop();
                vt.push_back(t->val);
                if (t->left)
                    qt.push(t->left); 
                if (t->right)
                    qt.push(t->right);
            }
            res.push_back(vt);
        }
        return res;
    }
};