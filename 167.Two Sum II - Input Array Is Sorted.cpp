/*
 * @lc app=leetcode id=167 lang=cpp
 * @lcpr version=30304
 *
 * [167] Two Sum II - Input Array Is Sorted
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;
        // 循环终止条件就是二者相等 因为题目说不能重复使用相同元素
        while (left < right)
        {
            auto sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                return {left + 1, right + 1};
            }
            else if (sum < target)//小了 让 left 增加
            {
                left++;
            }
            else //大了  就让 right 减少
            {
                right--;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */
