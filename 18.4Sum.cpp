/*
 * @lc app=leetcode id=18 lang=cpp
 * @lcpr version=30400
 *
 * [18] 4Sum
 */
#include "lc.h"
#include <functional>
// @lc code=start
class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());

        auto Nsum = [&](auto &&self, int n, int start, int target) -> vector<vector<int>> {
            if (n == 2)
            {
                auto left = start;
                int right = nums.size() - 1;
                vector<vector<int>> res2;
                while (left < right)
                {
                    auto temSum = nums[left] + nums[right];
                    if (temSum > target)
                    {
                        do
                            right--;
                        while (left < right && nums[right] == nums[right + 1]);
                    }
                    else if (temSum < target)
                    {
                        do
                            left++;
                        while (left < right && nums[left] == nums[left - 1]);
                    }
                    else
                    {
                        res2.push_back({nums[left], nums[right]});
                        do
                            right--;
                        while (left < right && nums[right] == nums[right + 1]);
                        do
                            left++;
                        while (left < right && nums[left] == nums[left - 1]);
                    }
                }
                return res2;
            }
            else if (n > 2)
            {
                vector<vector<int>> resN;
                for (int i = start; i < nums.size(); i++)
                {
                    if (i > start && nums[i] == nums[i - 1])
                        continue;
                    vector<vector<int>> resN_1 = self(self, n - 1, i + 1, target - nums[i]);
                    for (auto &res : resN_1)
                    {
                        res.push_back(nums[i]);
                        resN.push_back(res);
                    }
                }
                return resN;
            }
            else
            {
                throw;
            }
        };
        return Nsum(Nsum, 4, 0, target);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */
