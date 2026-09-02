class Solution 
{
public:
    void backtrack (vector<vector<int>>&ans, vector<int>&curr, int k, int target, int start)
    {
        if (curr.size() > k)
        return;

        if (target == 0 && curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            if (i > target)
            break;
            curr.push_back(i);
            backtrack(ans, curr, k, target - i, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>>ans;
        vector<int>curr;
        int target = n;
        backtrack(ans, curr, k, target, 1);
        return ans;
    }
};