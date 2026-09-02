class Solution {
public:
    void backtrack(set<vector<int>>&st, vector<int>&curr, int target, int start, vector<int>&candidates)
    {
        if (target == 0)
        {
            st.insert(curr);
            return;
        }

        if (target < 0)
        return;
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
            continue;
            if (candidates[i] > target)
            break;
            curr.push_back(candidates[i]);
            backtrack(st, curr, target - candidates[i], i + 1, candidates);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        set<vector<int>>st;
        vector<int>curr;
        sort(candidates.begin(), candidates.end());
        backtrack(st, curr, target, 0, candidates);
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};