class Solution 
{
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if (n == 0)
        return 1;
        int ans = 10;
        int choices = 9;
        for (int digits = 2; digits <= n; digits++)
        {
            choices *= (11 - digits);
            ans += choices;
        }
        return ans;
    }
};