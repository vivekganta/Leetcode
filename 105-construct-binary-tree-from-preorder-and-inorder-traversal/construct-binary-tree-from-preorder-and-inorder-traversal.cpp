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
    unordered_map<int, int>mp;
    int preindex = 0;
    TreeNode* build(vector<int>&preorder, int l, int r)
    {
        if (l > r)
        return NULL;
        int root_val = preorder[preindex++];
        TreeNode* root = new TreeNode (root_val);
        int mid = mp[root_val];

        root->left = build(preorder, l, mid - 1);
        root->right = build(preorder, mid + 1, r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;    
        return build(preorder, 0, preorder.size() - 1);
    }
};