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
    vector<int> ans;

    void solve(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        solve(root->left);       // 1. Left subtree
        ans.push_back(root->val); // 2. Store root value
        solve(root->right);      // 3. Right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        solve(root);
        return ans;
    }
};
