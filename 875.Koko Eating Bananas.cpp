/*
 * @lc app=leetcode id=875 lang=cpp
 * @lcpr version=30305
 *
 * [875] Koko Eating Bananas
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // k bigger, h smaller,
        // we need min k so we use left bound
        int left = 1;
        auto right = int(1e9 + 1);
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (f(mid, piles) <= h)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return right;
    }
    long f(int k, vector<int> &piles)
    {
        long res = 0;
        for (auto &p : piles)
        {
            res += p / k;
            res += p % k == 0 ? 0 : 1;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */
