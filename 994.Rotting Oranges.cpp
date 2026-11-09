/*
 * @lc app=leetcode id=994 lang=cpp
 * @lcpr version=30400
 *
 * [994] Rotting Oranges
 */
#include "lc.h"
#include <cstddef>
#include <queue>
#include <utility>
#include <vector>
// @lc code=start
class Solution
{
  public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        auto m = grid.size();
        auto n = grid[0].size();
        queue<vector<int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        auto step = 0;
        while (!q.empty())
        {

            auto size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();
                for (auto &dir : dirs)
                {
                    auto nxtX = front[0] + dir[0];
                    auto nxtY = front[1] + dir[1];
                    if (nxtX >= m || nxtX < 0 || nxtY >= n || nxtY < 0)
                    {
                        continue;
                    }
                    if (grid[nxtX][nxtY] == 1)
                    {
                        q.push({nxtX, nxtY});
                        grid[nxtX][nxtY] = 2;
                    }
                }
            }
            step++;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return step == 0 ? 0 : step - 1;
    }

    int orangesRotting_(vector<vector<int>> &grid)
    {
        // 标准 bfs
        queue<vector<int>> q;
        auto m = grid.size();
        auto n = grid[0].size();
        // 起点入队 ，这里起点不唯一 ，把所有的 2 入队
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        // 二维数组我们可以先定义好方向数组便于遍历
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int step = 0;
        while (!q.empty())
        {
            auto size = q.size();
            for (auto i = 0ul; i < size; i++)
            {
                auto coord = q.front();
                q.pop();
                for (auto &dir : dirs)
                {
                    int x = coord[0] + dir[0];
                    int y = coord[1] + dir[1];
                    if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1)
                    {
                        q.push({x, y});
                        grid[x][y] = 2; // 相当于visited 标记了
                    }
                }
            }
            step++;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return step == 0 ? 0 : step - 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */
