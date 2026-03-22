/*
 * @lc app=leetcode id=169 lang=cpp
 * @lcpr version=30400
 *
 * [169] Majority Element
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //非常巧妙
        int target = 0;
        int count = 0;
        for (int& n:nums){
            if (count==0) target=n;
            count+= n==target?1:-1;
        }
        return target;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */

