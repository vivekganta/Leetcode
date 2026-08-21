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
    void f(TreeNode* root, vector<int>&nums)
    {
        if(!root)
        return;
        f(root->left, nums);
        nums.push_back(root->val);
        f(root->right, nums);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>nums;
        f(root, nums);
        int ans = INT_MAX;
        for (int i = 1; i < nums.size(); i++)
        ans = min(ans, abs(nums[i] - nums[i - 1]));
        return ans;
    }
};