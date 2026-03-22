/*
 * @lc app=leetcode id=53 lang=cpp
 * @lcpr version=30400
 *
 * [53] Maximum Subarray
 */
#include "lc.h"
#include <climits>
#include <vector>
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> preSum(nums.size()+1,0);
        for (int i = 1;i<= nums.size();i++){
            preSum[i] = preSum[i-1]+nums[i-1];
        }
        int minPreSum = INT_MAX;
        int maxSum = INT_MIN;
        for (int i = 0;i<= nums.size();i++){
            maxSum = std::max(maxSum,preSum[i] - minPreSum);
            minPreSum = std::min(minPreSum,preSum[i]);
            
        }
        return maxSum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

