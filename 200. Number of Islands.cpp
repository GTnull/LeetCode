class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> check(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, check, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &check, int i, int j)
    {
        check[i][j] = true;
        grid[i][j] = '0';
        if (i > 0 && !check[i - 1][j] && grid[i - 1][j] == '1')
            dfs(grid, check, i - 1, j);
        if (i < grid.size() - 1 && !check[i + 1][j] && grid[i + 1][j] == '1')
            dfs(grid, check, i + 1, j);
        if (j > 0 && !check[i][j - 1] && grid[i][j - 1] == '1')
            dfs(grid, check, i, j - 1);
        if (j < grid[0].size() - 1 && !check[i][j + 1] && grid[i][j + 1] == '1')
            dfs(grid, check, i, j + 1);
    }
};