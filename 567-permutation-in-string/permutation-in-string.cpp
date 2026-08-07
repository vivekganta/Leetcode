class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
    {
        if (s1.size() > s2.size())
        return false;

        vector<int>S1(26, 0), S2(26, 0);
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            ++S1[s1[i] - 'a'];
            ++S2[s2[i] - 'a'];
        }
        if (S1 == S2)
        return true;

        for (int i = 1; i < s2.size() - n + 1; i++)
        {
            --S2[s2[i - 1] - 'a'];
            ++S2[s2[i + n - 1] - 'a'];

            if (S1 == S2)
            return true;
        }
        return false;
    }
};