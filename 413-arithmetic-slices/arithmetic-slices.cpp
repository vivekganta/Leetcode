class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int ans = 0;
        int n = nums.size();

        int left = 0;
        int right = 1;

        while (right < n - 1) 
        {
            if (nums[right] - nums[right - 1] == nums[right + 1] - nums[right]) 
            {
                left = right - 1;

                while (right < n - 1 && nums[right] - nums[right - 1] == nums[right + 1] - nums[right]) 
                ++right;
                
                int len = right - left + 1;
                ans += (len - 1) * (len - 2) / 2;
            }
            ++right;
        }
        return ans;
    }
};