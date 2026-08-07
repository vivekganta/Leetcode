class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        long long xor_all = 0;
        for(auto num : nums)
        xor_all ^= num;
        long long bit = xor_all & (-xor_all);
        int a = 0, b = 0;
        for (auto num : nums)
        {
            if (num & bit)
            a ^= num;
            else
            b ^= num;
        }
        return {a, b};
    }
};