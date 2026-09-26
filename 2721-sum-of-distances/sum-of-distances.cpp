class Solution 
{
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, pair<long long, long long>>mp;
        vector<long long>ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            int temp = nums[i];
            long long count = mp[temp].first;
            long long sum = mp[temp].second;
            
            ans[i] += (long long)i* count - sum;
            ++mp[temp].first;
            mp[temp].second += i;
        }

        mp.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            int temp = nums[i];
            long long count = mp[temp].first;
            long long sum = mp[temp].second;

            ans[i] += sum - (long long)i * count;
            ++mp[temp].first;
            mp[temp].second += i;
        }

        return ans;
    }
};