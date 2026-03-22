/*
 * @lc app=leetcode id=695 lang=cpp
 * @lcpr version=30400
 *
 * [695] Max Area of Island
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        function<bool(int, int, int &)> dfs = [&](int i, int j, int &count) {
            if (i < 0 || j < 0 || i >= m || j >= n)
            {
                // 超出索引边界
                return false;
            }
            if (grid[i][j] == 0)
            {
                return true;
            }
            grid[i][j] = 0;
            count++;
            bool res = 1;
            res *= dfs(i + 1, j, count);
            res *= dfs(i, j + 1, count);
            res *= dfs(i - 1, j, count);
            res *= dfs(i, j - 1, count);
            return res;
        };
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    int count = 0;
                    dfs(i,j,count);
                    maxArea = max(maxArea, count);
                }
            }
        }
        return maxArea;
    }
}

;
// @lc code=end

/*
// @lcpr case=start
//
[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */
