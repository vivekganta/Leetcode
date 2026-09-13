class Solution 
{
public:
    int minSwaps(string s) 
    {
        int ans = 0;
        int open = 0;
        for (char ch : s)
        {
            if (ch == '[')
            ++open;
            else
            --open;

            if (open < 0)
            {
                ++ans;
                open = 1;
            }
        }
        return ans;
    }
};