class Solution 
{
public:
    int maxLevelSum(TreeNode* root) 
    {
        int ans = INT_MIN;
        int l = 1;
        int level = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            int sum = 0;

            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->right)
                q.push(node->right);

                if(node->left)
                q.push(node->left);
            }

            if(sum > ans)
            {
                ans = sum;
                l = level;
            }
            ++level;
        }
        return l;
    }
};