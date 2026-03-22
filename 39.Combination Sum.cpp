/*
 * @lc app=leetcode id=39 lang=cpp
 * @lcpr version=30400
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <numeric>
#include <vector>
class Solution
{
  public:
    // 标准回溯算法 ，注意元素可不可以重复
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> solution;
        int curSum = 0;
        auto backtrack = [&](auto &self, int start = 0) {
            if (curSum > target || solution.size() >= 150)
                return;
            if (curSum == target)
            {
                res.push_back(solution);
                return;
            }

            for (int i = start; i < candidates.size(); i++)
            {
                solution.push_back(candidates[i]);
                curSum += candidates[i];
                self(self, i); // 直接传 i 就是可重复，如果不可重复就是 i+1
                solution.pop_back();
                curSum -= candidates[i];
            }
        };
        backtrack(backtrack);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
