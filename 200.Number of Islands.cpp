/*
 * @lc app=leetcode id=200 lang=cpp
 * @lcpr version=30400
 *
 * [200] Number of Islands
 */
#include "lc.h"
#include <functional>
// @lc code=start
class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        function<void(int ,int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n)
            {
                // 超出索引边界
                return;
            }
            if (grid[i][j]=='0'){
                return;
            }
            grid[i][j]='0';
            dfs(i+1,j);
            dfs(i,j+1);
            dfs(i-1,j);
            dfs(i,j-1);
        };
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j]=='1'){
                    res++;
                    dfs(i,j);
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
