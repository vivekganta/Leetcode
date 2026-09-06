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
    vector<TreeNode*> generateTrees(int n) 
    {
        return build(1, n);
    }
private:
    vector<TreeNode*>build(int start, int end)
    {
        vector<TreeNode*>result;
        if (start > end)
        {
            result.push_back(nullptr);
            return result;
        }

        for (int root = start; root <= end; root++)
        {
            vector<TreeNode*>leftTree = build(start, root - 1);
            vector<TreeNode*>rightTree = build(root + 1, end);

            for (TreeNode* left : leftTree)
            {
                for (TreeNode* right : rightTree)
                {
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;

                    result.push_back(node);
                }
            }
        }
        return result;
    }
};