class Solution 
{
public:
    void backtrack(vector<vector<int>>&ans, vector<int>&curr, vector<bool>&used, vector<int>&nums)
    {
        if (curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
            continue;

            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(ans, curr, used, nums);
            used[i] = false;
            curr.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>curr;
        vector<bool>used(nums.size(), false);

        backtrack(ans, curr, used, nums);
        return ans;
    }
};