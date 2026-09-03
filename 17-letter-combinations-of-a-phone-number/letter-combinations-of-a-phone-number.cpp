class Solution 
{
public:
    vector<string>mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string>ans;

    void backtrack (string &digits, int index, string &curr)
    {
        if (curr.size() == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        string temp = mp[digits[index] - '0'];
        for (char c : temp)
        {
            curr.push_back(c);
            backtrack(digits, index + 1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty())
        return {};

        string curr;
        backtrack (digits, 0, curr);
        return ans;
    }
};