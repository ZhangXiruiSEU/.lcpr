/*
 * @lc app=leetcode id=189 lang=cpp
 * @lcpr version=30400
 *
 * [189] Rotate Array
 */
#include "lc.h"
#include <iterator>
#include <vector>
// @lc code=start
class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());       // 全翻
        reverse(nums.begin(), nums.begin() + k); // 翻前 k 个
        reverse(nums.begin() + k, nums.end());   // 翻剩下的
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */
