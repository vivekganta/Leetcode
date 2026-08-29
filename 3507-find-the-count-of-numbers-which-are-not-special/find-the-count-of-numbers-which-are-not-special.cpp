class Solution 
{
public:
    int nonSpecialCount(int l, int r) 
    {
        int limit = sqrt(r);
        vector<bool>isPrime(limit + 1, true);
        if (limit >= 0)
        isPrime[0] = false;
        if (limit >= 1)
        isPrime[1] = false;

        for (int i = 4; i <= limit; i += 2)
        isPrime[i] = false;
        for (int i = 3; i * i <= limit; i += 2)
        {
            if(isPrime[i])
            for (int j = i * i; j <= limit; j += 2 * i)
            isPrime[j] = false;
        }

        int special = 0;
        for (int i = 2; i <= limit; i++)
        {
            if (isPrime[i])
            {
                int squ = i * i;
                if (squ >= l && squ <= r)
                ++special;
            }
        }

        return (r - l + 1) - special;
    }
};