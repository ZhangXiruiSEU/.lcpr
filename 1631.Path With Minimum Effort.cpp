/*
 * @lc app=leetcode id=1631 lang=cpp
 * @lcpr version=30402
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
#include <cstdlib>
#include <queue>
#include <vector>
class Solution
{

    class State
    {
      public:
        int x;
        int y;
        int totalCost;

        State(int x, int y, int totalCost = 0) : x(x), y(y), totalCost(totalCost) {};

        bool operator<(const State &other) const
        {
            return totalCost > other.totalCost;
        }
    };

    // vector<int> distTo(graph.size(), INT_MAX);
    auto bfs(vector<vector<int>> &heights) -> int
    {
        vector<vector<int>> effortTo(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        effortTo[0][0] = 0;

        priority_queue<State> pq;
        pq.push(State(0, 0));

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!pq.empty())
        {

            auto cur = pq.top();
            pq.pop();
            if (cur.x == heights.size() - 1 && cur.y == heights[0].size() - 1)
            {
                return cur.totalCost;
            }
            if (effortTo[cur.x][cur.y] < cur.totalCost)
            {
                continue;
            }

            for (auto dir : directions)
            {
                int next_x = cur.x + dir[0];
                int next_y = cur.y + dir[1];
                if (next_x < 0 || next_x >= heights.size() || next_y < 0 || next_y >= heights[0].size())
                {
                    continue;
                }

                auto stepCost = abs(heights[next_x][next_y] - heights[cur.x][cur.y]);
                auto wholeCost = max(cur.totalCost, stepCost);
                if (effortTo[next_x][next_y] <= wholeCost)
                {
                    continue;
                }
                pq.push(State(next_x, next_y, wholeCost));
                effortTo[next_x][next_y] = wholeCost;
            }
        }
        return -1;
    }

  public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {

        return bfs(heights);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,2],[3,8,2],[5,3,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[3,8,4],[5,3,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]\n
// @lcpr case=end

 */
