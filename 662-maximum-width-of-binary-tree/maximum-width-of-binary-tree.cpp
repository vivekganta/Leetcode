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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root)
        return 0;
        unsigned long long ans = 1;
        queue<pair<TreeNode*, unsigned long long>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            unsigned long long first = q.front().second;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto [node, index] = q.front();
                q.pop();
                index -= first;
                if(i == size - 1)
                ans = max(ans, index + 1);
                if (node->left)
                q.push({node->left, 2 * index + 1});
                if (node->right)
                q.push({node->right, 2 * index + 2});
            }
        }
        return (int)ans;
    }
};