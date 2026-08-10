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
    TreeNode* build(vector<int>&postorder, int l, int r, int &postindex, unordered_map<int, int>&mp)
    {
        if (l > r)
        return NULL;
        int root_val = postorder[postindex--];
        TreeNode* root = new TreeNode(root_val);

        int mid = mp[root_val];
        root->right = build(postorder, mid + 1, r, postindex, mp);
        root->left = build(postorder, l, mid - 1, postindex, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int, int>mp;
        for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
        int postindex = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1, postindex, mp);
    }
};