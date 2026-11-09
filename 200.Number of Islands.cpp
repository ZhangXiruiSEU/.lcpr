/*
 * @lc app=leetcode id=200 lang=cpp
 * @lcpr version=30400
 *
 * [200] Number of Islands
 */
#include "lc.h"
#include <functional>
#include <vector>
// @lc code=start
class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        auto dfs = [&](auto &self, int x, int y) {
            if (x >= m || x < 0 || y >= n || y < 0)
            {
                return;
            }
            if (grid[x][y] == '0')
            {
                return;
            }
            grid[x][y] = '0';
            self(self, x + 1, y);
            self(self, x - 1, y);
            self(self, x, y + 1);
            self(self, x, y - 1);
        };
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(dfs, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */
