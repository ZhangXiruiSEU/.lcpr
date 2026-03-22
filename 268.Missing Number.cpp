/*
 * @lc app=leetcode id=268 lang=cpp
 * @lcpr version=30400
 *
 * [268] Missing Number
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=nums.size();
        for (int i=0;i<nums.size();i++){
            res = res^i^nums[i];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [9,6,4,2,3,5,7,0,1]\n
// @lcpr case=end

 */

