/*
 * @lc app=leetcode id=34 lang=cpp
 * @lcpr version=30307
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include "lc.h"
#include <csignal>

// @lc code=start
namespace Binary_search {
int inline bs_left(vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size();
  while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] >= target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  if (right >= nums.size() || right < 0 || nums[right] != target)
    return -1;
  return right;
}

int inline bs_right(vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size();
  while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] <= target) {
      left = mid + 1;

    } else {
      right = mid;
    }
  }
  if (right - 1 >= nums.size() || right - 1 < 0 || nums[right - 1] != target)
    return -1;
  return right - 1;
}
} // namespace Binary_search
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> res(2, -2);
    res[0] = Binary_search::bs_left(nums, target);
    res[1] = Binary_search::bs_right(nums, target);
    return res;
    // int left = 0;
    // int right = nums.size();
    // while (left < right) {
    //   int mid = left + ((right - left) >> 1);
    //   if (nums[mid] >= target) {
    //     right = mid;
    //   } else {
    //     left = mid + 1;
    //   }
    // }
    // if (right>=nums.size()||right<0||nums[right]!=target) res[0]=-1;
    // else res[0]= right;

    // if (res[0] == -1) {
    //   res[1] = -1;
    //   return res;
    // }

    // left = 0;
    // right = nums.size();

    // while (left < right) {
    //   int mid = left + ((right - left) >> 1);
    //   if (nums[mid] <= target) {
    //     left = mid + 1;
    //   } else {
    //     right = mid;
    //   }
    // }

    // res[1] = left -1;
    // if (left -1>=nums.size()||left -1<0||nums[left -1]!=target) res[1]=-1;
    // else res[1]= left -1;
    // return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
