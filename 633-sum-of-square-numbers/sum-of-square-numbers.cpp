class Solution 
{
public:
    bool judgeSquareSum(int c) 
    {
        int left = 0;
        int right = sqrt(c);
        while(left <= right)
        {
            long long sum = (long long)left * left + right * right;
            if (sum == c)
            return true;
            else if (sum > c)
            right -= 1;
            else
            left += 1;
        }
        return false;
    }
};