/*
 * @lc app=leetcode id=1658 lang=cpp
 * @lcpr version=30400
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */
#include "lc.h"
#include <numeric>
// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // find the longest subarray whose sum is sum()-x
        int left = 0;
        int right = 0;
        int target = std::accumulate(nums.begin(),nums.end(),-x);

        int sum_win = 0;
        int max_len = -1;
        while (right<nums.size()){
            sum_win+=nums[right];
            right++;
            
            
            while (sum_win>target && left< right){
                sum_win -= nums[left];
                left++;
            }
            if (sum_win == target){
                max_len = std::max (max_len,right-left);
            }

        }
        return max_len == -1? -1:nums.size()-max_len;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,4,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5,6,7,8,9]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,20,1,1,3]\n10\n
// @lcpr case=end

 */

