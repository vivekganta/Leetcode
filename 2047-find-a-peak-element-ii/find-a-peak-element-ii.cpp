class Solution 
{
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int rows = mat.size();
        int cols = mat[0].size();

        int top = 0;
        int bottom = rows - 1;
        while (top <= bottom)
        {
            int mid_row = top + (bottom - top) / 2;
            int max_col = 0;
            for (int col = 1; col < cols; col++)
            if (mat[mid_row][col] > mat[mid_row][max_col])
            max_col = col;

            int up = -1, down = -1;
            if (mid_row > 0)
            up = mat[mid_row - 1][max_col];
            if (mid_row < rows - 1)
            down = mat[mid_row + 1][max_col];

            if (mat[mid_row][max_col] > up && mat[mid_row][max_col] > down)
            return {mid_row, max_col};

            if (mat[mid_row][max_col] < up)
            bottom = mid_row - 1;
            else
            top = mid_row + 1;
        }
        return {-1, -1};
    }
};