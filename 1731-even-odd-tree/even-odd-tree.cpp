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
    bool isEvenOddTree(TreeNode* root) 
    {
        bool flag = true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int prev;
            if (flag)
            prev = INT_MIN;
            else
            prev = INT_MAX;
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (flag)
                {
                    if (node->val % 2 == 0)
                    return false;
                    if (node->val <= prev)
                    return false;
                }
                else
                {
                    if (node->val % 2 != 0)
                    return false;
                    if (node->val >= prev)
                    return false;
                }
                prev = node->val;
                if (node->left)
                q.push(node->left);
                if (node->right)
                q.push(node->right);
            }
            flag = !flag;
        }
        return true;
    }
};