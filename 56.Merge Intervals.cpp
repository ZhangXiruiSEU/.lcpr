/*
 * @lc app=leetcode id=56 lang=cpp
 * @lcpr version=30400
 *
 * [56] Merge Intervals
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        for (auto &interval : intervals)
        {
            if (result.empty())
            {
                result.push_back(interval);
                continue;
            }
            auto &last_res = result.back();
            if (last_res[1] < interval[0])
            {
                result.push_back(interval);
            }

            else
            {
                last_res[1] = interval[1];
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,7],[1,4]]\n
// @lcpr case=end

 */
