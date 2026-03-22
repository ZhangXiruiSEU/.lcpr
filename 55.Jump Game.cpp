/*
 * @lc app=leetcode id=55 lang=cpp
 * @lcpr version=30400
 *
 * [55] Jump Game
 */
# include "lc.h"
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for (int i =0;i<nums.size();i++){
            if (i>max_reach) return false;
            max_reach = std::max(max_reach,i+nums[i]);
            if (max_reach>=nums.size()-1) return true;
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */

