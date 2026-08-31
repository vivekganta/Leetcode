class Solution 
{
public:
    int m, n;
    bool dfs (string word, int i, int j, int k, vector<vector<char>>&board)
    {
        if (k == word.size())
        return true;
        if (i < 0 || i >= m || j < 0 || j >= n)
        return false;
        if (board[i][j] != word[k])
        return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = (dfs(word, i, j + 1, k + 1, board) || dfs(word, i, j - 1, k + 1, board)
                   || dfs(word, i - 1, j, k + 1, board) || dfs(word, i + 1, j, k + 1, board));

        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        m = board.size();
        n = board[0].size();
       
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                if(dfs(word, i, j, 0, board))
                return true;
            }
        }
        return false;
    }
};