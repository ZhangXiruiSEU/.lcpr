/*
 * @lc app=leetcode id=300 lang=cpp
 * @lcpr version=30307
 *
 * [300] Longest Increasing Subsequence
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        memo[0] = 1;
        auto dp = [&](auto &&self, int indx) {
            if (memo[indx] != -1)
                return memo[indx];
            int max_before = 0;
            for (int i = 0; i < indx; i++)
            {
                if (nums[i] < nums[indx])
                {
                    max_before = max(max_before, self(self, i));
                }
            }
            // cout<<indx<<"值"<<nums[indx]<<"前面最大的是"<<max_before<<endl;
            memo[indx] = max_before + 1;
            return memo[indx];
        };
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
            max = std::max(max, dp(dp, i));
        return max;
    }
    int lengthOfLIS_magic(vector<int> &nums)
    {
        int piles(0);
        vector<int> pile_top(nums.size(), 0);
        for (const auto &n : nums)
        {
            int f = 0;
            f = search(0, piles, pile_top, n);
            if (f == piles)
            {
                pile_top[piles] = n;
                piles++;
            }
            else
            {
                pile_top[f] = n;
            }
        }
        return piles;
    }
    int search(int left, int right, vector<int> &pt, int n)
    {
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (n > pt[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */
