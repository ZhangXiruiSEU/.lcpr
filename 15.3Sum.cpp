/*
 * @lc app=leetcode id=15 lang=cpp
 * @lcpr version=30400
 *
 * [15] 3Sum
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        std::sort(nums.begin(), nums.end());

        auto twoSum = [&](int start, int target) -> vector<vector<int>> {
            int left = start;
            int right = nums.size() - 1;
            vector<vector<int>> res;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
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
        int target = 0;
        vector<vector<int>> res3;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            auto res2 = twoSum(i + 1, target - nums[i]);
            for (auto &r : res2)
            {
                r.push_back(nums[i]);
                res3.push_back(r);
            }
        }
        return res3;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
