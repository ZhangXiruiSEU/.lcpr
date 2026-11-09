/*
 * @lc app=leetcode id=136 lang=cpp
 * @lcpr version=30400
 *
 * [136] Single Number
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0b0;
        for (auto &num : nums)
        {
            res ^= num;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
