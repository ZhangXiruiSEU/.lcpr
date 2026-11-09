/*
 * @lc app=leetcode id=1254 lang=cpp
 * @lcpr version=30400
 *
 * [1254] Number of Closed Islands
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n)
            {
                return; // 超出索引边界
            }
            if (grid[i][j] == 1) // 如果是海水
            {
                return;
            }
            grid[i][j] = 1; // 不是海水改成海水
            dfs(i + 1, j);
            dfs(i, j + 1);
            dfs(i - 1, j);
            dfs(i, j - 1);
        };

        for (int i = 0; i < grid.size(); i++)
        {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for (int j = 0; j < grid[0].size(); j++)
        {
            dfs(0, j);
            dfs(m - 1, j);
        }
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 0) // 如果是陆地
                {
                    res++;
                    dfs(i, j);
                }
            }
        }
        return res;
    }
    int closedIsland_old(vector<vector<int>> &grid)
    {

        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n)
            {
                // 超出索引边界
                return false;
            }
            if (grid[i][j] == 1)
            {
                return true;
            }
            grid[i][j] = 1;
            bool res = 1;
            res *= dfs(i + 1, j);
            res *= dfs(i, j + 1);
            res *= dfs(i - 1, j);
            res *= dfs(i, j - 1);
            return res;
        };
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 0)
                {

                    if (dfs(i, j))
                        res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1,1,1],[1,0,0,0,0,0,1],[1,0,1,1,1,0,1],[1,0,1,0,1,0,1],[1,0,1,1,1,0,1],[1,0,0,0,0,0,1],[1,1,1,1,1,1,1]]\n
// @lcpr case=end

 */
