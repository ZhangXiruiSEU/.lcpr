/*
 * @lc app=leetcode id=33 lang=cpp
 * @lcpr version=30401
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
  public:
    // 复盘的时候重新想想，这个也是直接照抄的
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // 如果说找mid 就是 target
            if (nums[mid] == target)
            {
                return mid;
            }
            //
            if (nums[mid] >= nums[left])
            {
                // mid 落在断崖左边，此时 nums[left..mid] 有序

                // 如果说目标 是在有序的left…mid 区间
                if (target >= nums[left] && target <= nums[mid])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else // mid 落在断崖右边，此时 nums[mid..right] 有序
            {
                if (target <= nums[right - 1] && target >= nums[mid])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
