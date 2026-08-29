class Solution 
{
public:
    int countPrimes(int n) 
    {
        if (n < 3)
        return 0;
        int c = 0;
        vector<bool>isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        c = 1;
        for (int i = 3; i * i < n; i += 2)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j < n; j += 2 * i)
                isPrime[j] = false;
            }
        }
        for (int i = 3; i < n; i += 2)
        if (isPrime[i])
        ++c;
        return c;
    }
};