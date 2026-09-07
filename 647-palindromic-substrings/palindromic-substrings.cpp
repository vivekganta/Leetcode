class Solution 
{
public:
    int expand(int left, int right, string s)
    {
        int count = 0;
        while (right < s.size() && left >= 0 && s[left] == s[right])
        {
            ++count;
            --left;
            ++right;
        }
        return count;
    }

    int countSubstrings(string s) 
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans += expand(i, i, s);
            ans += expand(i, i + 1, s);
        }
        return ans;
    }
};