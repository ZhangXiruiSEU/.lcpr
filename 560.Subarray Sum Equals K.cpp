/*
 * @lc app=leetcode id=560 lang=cpp
 * @lcpr version=30400
 *
 * [560] Subarray Sum Equals K
 */
#include "lc.h"
#include <unordered_set>
// @lc code=start
class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int res = 0;
        unordered_map<int, int> mp;

        // 遍历数组元素
        for (auto &num : nums)
        {
            // 记录现在的 sum 值，编入哈希表
            // 每个前缀和都编进去
            // 一定要记录次数
            // 如 1 -1 0 这种情况 
            mp[sum]++;
            sum += num;

            // 如果现在的和 减去 目标 以前出现过，
            // 说明有子数组满足条件了，然后加上出现的次数就行了
            if (mp.count(sum - k) == 1)
                res += mp[sum - k];
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */
