/*
 * @lc app=leetcode id=283 lang=cpp
 * @lcpr version=30304
 *
 * [283] Move Zeroes
 */
#include <vector>
using std::vector;

// @lc code=start
class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        int fast = 0, slow = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != 0)
            {
                swap(nums[slow], nums[fast]);
                slow++;
            }
            fast++;
        }
    }

    void moveZeroes_(vector<int> &nums)
    {
        int fast = 0, slow = 0;
        // 快慢指针
        // 指向待处理的位置
        while (fast < nums.size())
        {
            // 如果快指针不为零，直接把慢指针的值变成快指针的值
            // 相当于把所有不为零的值挪到前面去
            if (nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                // 挪了之后就慢指针前进
                slow++;
            }
            // 快指针一直走
            fast++;
        }
        // 慢指针之后的全部变成零
        while (slow < nums.size())
        {
            nums[slow] = 0;
            slow++;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
