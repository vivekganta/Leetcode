class Solution 
{
public:
    void backtrack (set<vector<int>>&st, vector<int>&curr, vector<bool>&used, vector<int>&nums)
    {
        if (curr.size() == nums.size())
        {
            st.insert(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
            continue;
            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(st, curr, used, nums);

            used[i] = false;
            curr.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        set<vector<int>>st;
        vector<int>curr;
        vector<bool>used(nums.size(), false);

        backtrack(st, curr, used, nums);
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};