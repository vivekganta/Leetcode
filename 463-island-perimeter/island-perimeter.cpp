class Solution 
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int ans = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == 0)
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};