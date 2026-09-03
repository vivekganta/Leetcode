class Solution 
{
public:
    int backtrack (vector<int>&nums, int target, vector<int>&dp)
    {
        if (target == 0)
        return 1;
        if (target < 0)
        return 0;
        if (dp[target] != -1)
        return dp[target];

        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > target)
            break;
            temp += backtrack(nums, target - nums[i], dp);
        }

        return dp[target] = temp;
    }

    int combinationSum4(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<int>dp(target + 1, -1);
        int ans = backtrack(nums, target, dp);
        return ans;
    }
};