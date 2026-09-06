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
class Solution 
{
public:
    void backtrack (vector<vector<int>>&ans, vector<int>&curr, int target, TreeNode* node)
    {
        if (node == nullptr)
        return;

        curr.push_back(node->val);
        if (!node->left && !node->right && node->val == target)
        ans.push_back(curr);
            
        backtrack (ans, curr, target - node->val, node->left);
        backtrack (ans, curr, target - node->val, node->right);
        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>>ans;
        vector<int>curr;
        backtrack(ans, curr, targetSum, root);
        return ans;
    }
};