/*
 * @lc app=leetcode id=35 lang=cpp
 * @lcpr version=30401
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution
{
  public:
    // 基本的搜索边界的二分搜索模板
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        int res;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                right = mid;
            }
            else if (nums[mid] < target)
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
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */
