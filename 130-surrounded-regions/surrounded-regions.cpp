class Solution 
{
public:
    void solve(vector<vector<char>>& board) 
    {
        if (board.empty())
        return;

        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        for (int c = 0; c < m; c++)
        {
            if (board[0][c] == 'O')
            {
                board[0][c] = '#';
                q.push({0, c});
            }

            if (board[n - 1][c] == 'O')
            {
                board[n - 1][c] = '#';
                q.push({n - 1, c});
            }
        }

        for (int r = 0; r < n; r++)
        {
            if (board[r][0] == 'O')
            {
                board[r][0] = '#';
                q.push({r, 0});
            }

            if (board[r][m - 1] == 'O')
            {
                board[r][m - 1] = '#';
                q.push({r, m - 1});
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m && board[nr][nc] == 'O')
                {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                board[i][j] = 'X';
                else if (board[i][j] == '#')
                board[i][j] = 'O';
            }
        }
    }
};