class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        set<long long>st;
        long long maxi = INT_MIN, mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, 1LL *nums[i]);
            mini = min(mini, 1LL * nums[i]);
            st.insert(nums[i]);
        }
        for (long long i = mini + 1; i < maxi; i++)
        if (st.find(i) == st.end())
        ans.push_back(i);

        if (ans.size() > 0)
        return ans;
        else
        return {};
    }
};