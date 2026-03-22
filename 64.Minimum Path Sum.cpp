/*
 * @lc app=leetcode id=64 lang=cpp
 * @lcpr version=30400
 *
 * [64] Minimum Path Sum
 */
#include "lc.h"
#include <climits>
#include <functional>
#include <vector>
// @lc code=start
class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<int> dp(grid[0].size(), INT_MAX);
        dp[0] = 0;
        for (auto &row : grid)
        {
            dp[0] += row[0]; // 更新当前行的第一个元素
            for (int j = 1; j < grid[0].size(); j++)
            {
                // dp[j] 是上方的，dp[j-1] 是左边的
                dp[j] = min(dp[j], dp[j - 1]) + row[j];
            }
            
        }
        return dp[grid[0].size() - 1];
    }
    int minPathSum_recur(vector<vector<int>> &grid)
    {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        function<int(int, int)> dp = [&](int x, int y) {
            if (x == 0 && y == 0)
                return grid[0][0]; // basecase
            // the minimum of left and upper
            //  if exist!
            if (memo[x][y] != -1)
                return memo[x][y];
            // left
            int left = INT_MAX;
            int upper = INT_MAX;
            if (x - 1 >= 0)
            {
                upper = dp(x - 1, y);
            }
            if (y - 1 >= 0)
            {
                left = dp(x, y - 1);
            }
            memo[x][y] = min(left, upper) + grid[x][y];
            return memo[x][y];
        };
        return dp(grid.size() - 1, grid[0].size() - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */
