class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int ans = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            { 
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    queue<pair<int, int>>q;
                    q.push({i, j});
                    ++ans;
                    visited[i][j] = true;
                    while(!q.empty())
                    {
                        auto[r, c] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int sr = r + dr[k];
                            int sc = c + dc[k];
                            if(sr >= 0 && sr < m && sc >= 0 && sc < n && grid[sr][sc] == '1' && !visited[sr][sc])
                            {
                                q.push({sr, sc});
                                visited[sr][sc] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};