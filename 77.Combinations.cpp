/*
 * @lc app=leetcode id=77 lang=cpp
 * @lcpr version=30400
 *
 * [77] Combinations
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    vector<vector<int>> combine(int n, int k)
    {
        // C n k
        vector<int> temp;
        vector<vector<int>> res;

        auto backtrack = [&](auto &&self, int start) {
            if (temp.size() == k)
            {
                res.push_back(temp);
                return;
            }
            for (int i = start; i <= n; i++)
            {
                temp.push_back(i);
                self(self, i + 1);
                temp.pop_back();
            }
        };
        backtrack(backtrack, 1);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
