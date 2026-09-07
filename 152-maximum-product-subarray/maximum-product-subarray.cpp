class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int oldmax = nums[0];
        int oldmin = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int newmax = max({nums[i], oldmax * nums[i], oldmin * nums[i]});
            int newmin = min({nums[i], oldmax * nums[i], oldmin * nums[i]});
            oldmax = newmax;
            oldmin = newmin;
            ans = max (ans, oldmax);
        }
        return ans;
    }
};