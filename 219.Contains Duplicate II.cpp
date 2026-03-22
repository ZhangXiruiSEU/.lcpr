/*
 * @lc app=leetcode id=219 lang=cpp
 * @lcpr version=30400
 *
 * [219] Contains Duplicate II
 */
#include "lc.h"
#include <unordered_set>
// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0, right = 0;
        unordered_set<int> window;
        // 滑动窗口算法框架，维护一个大小为 k 的窗口
        while (right < nums.size()) {
            // 扩大窗口
            if (window.find(nums[right]) != window.end()) {
                return true;
            }
            window.insert(nums[right]);
            right++;

            if (right - left > k) {
                // 当窗口的大小大于 k 时，缩小窗口
                window.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */

