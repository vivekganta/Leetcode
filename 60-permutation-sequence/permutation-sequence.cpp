class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        vector<int>nums;
        for (int i = 1; i <= n; i++)
        nums.push_back(i);
        string ans = "";

        --k;
        for (int i = n; i > 0; i--)
        {
            int fact = 1;
            for (int j = 1; j < i; j++)
            fact *= j;

            int index = k / fact;
            ans += to_string(nums[index]);
            k %= fact;
            nums.erase(nums.begin() + index);
        }
        return ans;
    }
};