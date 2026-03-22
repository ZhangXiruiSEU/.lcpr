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
        auto twoSum = [&](int start, long target) -> vector<vector<int>> {
            int left = start;
            int right = nums.size() - 1;
            vector<vector<int>> res;
            while (left < right)
            {
                long sum = nums[left] + nums[right];
                int leftVal = nums[left], rightVal = nums[right];
                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    res.push_back({nums[left], nums[right]});
                    while (left < right && leftVal == nums[left])
                        left++;
                    while (left < right && rightVal == nums[right])
                        right--;
                }
            }
            return res;
        };
        std::sort(nums.begin(), nums.end());
        function<vector<vector<int>>(int, int, long)> nSum = [&](int n, int start, long target) -> vector<vector<int>> {
            if (n == 2)
                return twoSum(start, target);
            else
            {
                vector<vector<int>> resn;
                for (int i = start; i < nums.size(); i++)
                {
                    if ((long long)n * nums[i] > target)
                        break;
                    if ((long long)nums[i] + (long long)(n - 1) * nums[nums.size() - 1] < target)
                        continue;
                    if (i > start && nums[i] == nums[i - 1])
                    {
                        continue;
                    }
                    auto res = nSum(n - 1, i + 1, target - nums[i]);
                    for (auto &r : res)
                    {
                        r.push_back(nums[i]);
                        resn.push_back(r);
                    }
                }
                return resn;
            }
        };

        return nSum(4, 0, target);
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
