/*
 * @lc app=leetcode id=26 lang=cpp
 * @lcpr version=30304
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        // 快慢指针的技巧
        int fast = 0;
        int slow = 0;
        // 快指针不断地找新的元素
        // 快指针达到终点就退出
        while (fast < nums.size())
        {
            // 如果快指针慢指针对象不同，说明遇到了下一个不重复的元素
            if (nums[fast] != nums[slow])
            {
                slow++;//慢指针进一步
                //然后把进一步后的位置写成那个不同的元素
                nums[slow] = nums[fast];

            }
            //每次循环结束前都要 fast 进一步
            fast += 1;
        }
        return slow + 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */
