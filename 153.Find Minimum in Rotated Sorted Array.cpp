/*
 * @lc app=leetcode id=153 lang=cpp
 * @lcpr version=30401
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
  public:
  // 这个题边界情况很鸡儿多
    int findMin(vector<int> &nums)
    {
        
        int left = 0, right = nums.size();
        if (nums[left]<=nums[right-1]) {
            return nums[left];
        }

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums.front()){
                left = mid +1;
            }
            else {
                right = mid;
            }
        }
        return nums[right];

    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,15,17]\n
// @lcpr case=end

 */
