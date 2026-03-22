/*
 * @lc app=leetcode id=152 lang=cpp
 * @lcpr version=30400
 *
 * [152] Maximum Product Subarray
 */
#include "lc.h"
#include <climits>
#include <utility>
#include <vector>
// @lc code=start
class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        int pre_max = nums[0];
        int pre_min = nums[0];
        int max_product = pre_max;
        for (int i = 1; i < nums.size(); i++)
        {
            auto cur_max = max({nums[i],nums[i] * pre_max, nums[i] * pre_min});
            auto cur_min = min({nums[i], nums[i] * pre_max, nums[i] * pre_min});
            max_product = max(max_product,cur_max);
            pre_max = cur_max;
            pre_min = cur_min;

        }
        return max_product;
    }

    int maxProduct_recur(vector<int> &nums)
    {
        // pair 第一个最大，第二个最小
        vector<pair<int, int>> memo(nums.size(), {0, 0});
        vector<bool> visited(nums.size(), false);
        // 以索引 i 结尾的最大和最小product
        auto dp = [&](auto &self, int i) -> pair<int, int> {
            if (i == 0)
                return {nums[i], nums[i]};
            if (visited[i] != false)
                return memo[i];

            // 三种情况都可能是最大值或最小值
            // 自己，乘以最大，乘以最小
            auto [pre_max, pre_min] = self(self, i - 1);

            auto max_val = max({nums[i], nums[i] * pre_max, nums[i] * pre_min});
            auto min_val = min({nums[i], nums[i] * pre_max, nums[i] * pre_min});

            memo[i] = {max_val, min_val};
            visited[i] = true;
            return memo[i];
        };
        int max_val = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            max_val = max(max_val, dp(dp, i).first);
        }
        return max_val;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

 */
