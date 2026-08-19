class Solution 
{
public:
    int n, m;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    void dfs(int r, int c, vector<vector<int>>&image, int newcolor, int oldcolor)
    {
        if(r < 0 || c < 0 || r >= n || c >= m)
        return;
        if(image[r][c] != oldcolor)
        return;
        image[r][c] = newcolor;
        for(int k = 0; k < 4; k++)
        {
            int sr = r + dr[k];
            int sc = c + dc[k];
            dfs(sr, sc, image, newcolor, oldcolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        n = image.size();
        m = image[0].size();
        int oldcolor = image[sr][sc];
        if(oldcolor == color)
        return image;
        dfs(sr, sc, image, color, oldcolor);
        return image;
    }
};