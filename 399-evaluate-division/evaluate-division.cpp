class Solution 
{
public:
    unordered_map<string, vector<pair<string, double>>>adj;
    double dfs(unordered_set<string>&visited, string src, string dest)
    {
        if (src == dest)
        return 1.0;
        visited.insert(src);
        for (auto &[neigh, weight] : adj[src])
        {
            if (visited.count(neigh))
            continue;

            double result = dfs(visited, neigh, dest);
            if (result != -1)
            return weight * result;
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        for (int i = 0; i < equations.size(); i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double weight = values[i];

            adj[a].push_back({b, weight});
            adj[b].push_back({a, 1.0 / weight});
        }

        vector<double>ans;
        for (auto &query : queries)
        {
            string src = query[0];
            string dest = query[1];

            if (!adj.count(src) || !adj.count(dest))
            {
                ans.push_back(-1.0);
                continue;
            }
                
            unordered_set<string>visited;
            double res = dfs(visited, src, dest);
            ans.push_back(res);
        }
        return ans;
    }
};