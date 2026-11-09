/*
 * @lc app=leetcode id=53 lang=cpp
 * @lcpr version=30400
 *
 * [53] Maximum Subarray
 */
#include "lc.h"
#include <algorithm>
#include <climits>
#include <vector>
// @lc code=start
class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size()==0) return 0;
        int temp = nums[0];
        int maxv = temp;
        for (int i = 1; i < nums.size(); i++)
        {
            temp = max(nums[i], nums[i] + temp);
            maxv = max(maxv,temp);
        }
        return maxv;
    }
    int maxSubArray__(vector<int> &nums)
    {
        // dp (i)  以 num[i] 结尾的最大子数组的和
        // dp(i)  = max(dp(i-1)+nums[i] , nums[i]
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }

    int maxSubArray_(vector<int> &nums)
    {
        vector<int> preSum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        int minPreSum = 0;
        int maxSum = nums[0];
        for (int i = 1; i <= nums.size(); i++)
        {
            maxSum = std::max(maxSum, preSum[i] - minPreSum);
            minPreSum = std::min(minPreSum, preSum[i]);
        }
        return maxSum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
