class Solution 
{
public:
    void backtrack (vector<vector<int>>&ans, vector<int>&curr, vector<int>&nums, int start)
    {
        if (curr.size() >= 2)
        ans.push_back(curr);

        unordered_set<int>used;
        for (int i = start; i < nums.size(); i++)
        {
            if (used.count(nums[i]))
            continue;
            if (!curr.empty() && nums[i] < curr.back())
            continue;

            used.insert(nums[i]);
            curr.push_back(nums[i]);
            backtrack(ans, curr, nums, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>curr;
        backtrack(ans, curr, nums, 0);
        return ans;
    }
};