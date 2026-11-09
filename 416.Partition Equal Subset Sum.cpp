/*
 * @lc app=leetcode id=416 lang=cpp
 * @lcpr version=30307
 *
 * [416] Partition Equal Subset Sum
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution
{
  public:
    vector<vector<char>> memo;
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (const auto &n : nums)
            sum += n;
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        // 找到一个等于sum 的一半的分法

        // 0 - 1 背包问题 ： 背包容量确定 装东西让价值最大 这道题价值就是容量
        //
        // dp[i][w]  考虑前 i 个物品 当前背包容量是w   dp 就是最大负载
        // =max (  dp[i-1][w-nums[i-1]]   dp[i-1][w] )

        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum+1, 0));
        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (j - nums[i - 1] >= 0)
                    dp[i][j] = max({dp[i - 1][j - nums[i - 1]]+nums[i-1], dp[i - 1][j]});
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[nums.size()][sum] == sum;
        
    }

    bool canPartition_(vector<int> &nums)
    {
        int sum = 0;
        for (const auto &n : nums)
            sum += n;
        if (sum % 2 != 0)
            return false;
        sum /= 2;

        memo.resize(nums.size() + 1, vector<char>(sum + 1, -1)); //-1 means undefined

        return dp(nums, nums.size() - 1, sum);
    }
    bool dp(vector<int> &nums, int i, int sum)
    {
        if (sum == 0)
            return true;
        if (sum < 0 || i < 0)
            return false;
        // boundary condition

        // check the memo
        if (memo[i][sum] != -1)
            return memo[i][sum];
        auto res = dp(nums, i - 1, sum)               // whether i-th is useless
                   || dp(nums, i - 1, sum - nums[i]); // or with i, perfectly filled, which means
        // without i ,sum-nums[i] can also be perfectly filled

        memo[i][sum] = res;
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */
