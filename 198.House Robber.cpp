/*
 * @lc app=leetcode id=198 lang=cpp
 * @lcpr version=30400
 *
 * [198] House Robber
 */
#include "lc.h"
#include <functional>
#include <vector>
// @lc code=start
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        std::array<int,2> pre ({nums[0],0});
        
        for (int i = 2; i <= nums.size(); i++)
        {

              int cur =std::max(pre[0], nums[i - 1] + pre[1]);
             pre[1] = pre[0];
             pre[0] = cur;

        }
        return pre[0];
    }

    int rob_recur(vector<int> &nums)
    {
        vector<int> memo(nums.size() + 1, -1);

        // keep in mind  n, represent the n-th , no the index
        // hard to think backward, let do it forward
        function<int(int)> dp = [&](int n) -> int {
            if (memo[n] != -1)
                return memo[n];
            if (n <= 0)
                return 0;
            if (n == 1)
                return nums[0];
            memo[n] = std::max(nums[n - 1] + dp(n - 2), dp(n - 1));
            return memo[n];
        };
        return dp(nums.size());
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */
