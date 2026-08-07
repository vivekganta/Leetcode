class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size() - 1;
        int ans = 0;

        for (int bit_i = 0; bit_i < 32; bit_i++)
        {
            int count_bit_i = 0;
            int actual_bit_i = 0;
            for(int i = 0; i <= n; i++)
            if (nums[i] & (1 << bit_i))
            ++count_bit_i;

            for (int i = 1; i <= n; i++)
            if (i & (1 << bit_i))
            ++actual_bit_i;

            if (count_bit_i > actual_bit_i)
            ans |= (1 << bit_i);
        }    
        return ans;
    }
};