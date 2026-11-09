/*
 * @lc app=leetcode id=27 lang=cpp
 * @lcpr version=30304
 *
 * [27] Remove Element
 */
#include "lc.h"

// @lc code=start
class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int fast = 0;
        int slow = 0;

        while (fast < nums.size())
        {
            // slow 指向要改的地方，（除了开始的时候）要删除的元素
            // fast 去探测后面的到底是不是我要删的 如果不是，我就把他写会 slow 的位置
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */
