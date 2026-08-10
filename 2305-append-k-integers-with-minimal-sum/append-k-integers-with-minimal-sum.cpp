class Solution 
{
public:
    long long minimalKSum(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        vector<int> arr;
        for (int x : nums) 
        {
            if (arr.empty() || arr.back() != x)
            arr.push_back(x);
        }

        long long ans = 0;
        long long curr = 1;

        for (int x : arr) 
        {
            if (x > curr) 
            {
                long long count = x - curr;
                long long take = min((long long)k, count);

                ans += take * (2 * curr + take - 1) / 2;

                k -= take;
                if (k == 0)
                return ans;
            }
            curr = x + 1;
        }

        while (k > 0) 
        {
            ans += curr;
            ++curr;
            --k;
        }

        return ans;
    }
};