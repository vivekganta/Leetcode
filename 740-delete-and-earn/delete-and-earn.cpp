class Solution 
{
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        vector<int>value(100001, 0);
        for (int num : nums)
        value[num] += num;
        vector<int>dp(100001, 0);
        dp[0] = 0;
        dp[1] = value[1];
        for (int i = 2; i <= 10000; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + value[i]);
        return dp[10000];
    }
};