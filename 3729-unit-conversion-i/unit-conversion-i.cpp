class Solution 
{
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) 
    {
        const long long mod = 1e9 + 7;
        int n = conversions.size() + 1;
        vector<int>ans(n);
        vector<vector<pair<int, long long>>>adj(n);

        for (auto &c : conversions)
        {
            int u = c[0];
            int v = c[1];
            long long x = c[2];
            adj[u].push_back({v, x});
        }

        queue<int>q;
        q.push(0);
        ans[0] = 1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto[v, x] : adj[u])
            {
                ans[v] = (ans[u] * x) % mod;
                q.push(v);
            }
        }

        return ans;
    }
};