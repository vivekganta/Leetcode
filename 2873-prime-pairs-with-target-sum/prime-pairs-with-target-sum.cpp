class Solution 
{
public:
    vector<vector<int>> findPrimePairs(int n) 
    {
        unordered_set<int> primes;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
            }
        }

        for (int i = 2; i <= n; i++)
        if (isPrime[i])
        primes.insert(i);
        
        vector<vector<int>>ans;
        for (int i = 2; i <= n / 2; i++)
        if (primes.count(i) && primes.count(n - i))
        ans.push_back({i, n - i});
        return ans;
    }
};