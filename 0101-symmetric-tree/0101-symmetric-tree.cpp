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

    bool Solve(TreeNode* p, TreeNode*q)
    {
         if(p == NULL && q == NULL)
        return true;
        if(p == NULL || q == NULL)
        return false;
        if(p->val != q->val)
        return false;

        bool r1 = Solve(p->left, q->right);
        bool r2 = Solve(p->right, q->left);
        return (r1&r2);

    }
    bool isSymmetric(TreeNode* root) {
        return Solve(root -> left, root -> right);
    }
};