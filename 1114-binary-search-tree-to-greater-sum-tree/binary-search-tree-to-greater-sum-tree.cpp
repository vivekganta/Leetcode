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
    int sum = 0;
    void reverse_inorder(TreeNode* root)
    {
        if (root == nullptr)
        return;

        reverse_inorder(root->right);
        sum += root->val;
        root->val = sum;
        reverse_inorder(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        reverse_inorder(root);
        return root;
    }
};