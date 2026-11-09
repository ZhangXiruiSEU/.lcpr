/*
 * @lc app=leetcode id=75 lang=cpp
 * @lcpr version=30400
 *
 * [75] Sort Colors
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int p0 = -1;
        int p1 = nums.size();
        // we take close interval here
        int i = 0;
        int mid = 1;
        while (i < p1)
        {
            if (nums[i] > mid)
            {
                p1--;
                swap(nums[i], nums[p1]);
            }
            else if (nums[i] < mid)
            {
                p0++;
                swap(nums[i], nums[p0]);
                i++;
            }
            else
            {
                i++;
            }
        }
        
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */
