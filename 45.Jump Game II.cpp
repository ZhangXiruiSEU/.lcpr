/*
 * @lc app=leetcode id=45 lang=cpp
 * @lcpr version=30400
 *
 * [45] Jump Game II
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int jump_number = 0;
        int cur = 0;
        int max_reach = 0;
        for (int i =0;i<nums.size();i++){
            if (cur>=nums.size()-1) break;
            max_reach = max(max_reach,i+ nums[i]);
            
            if (i== cur){
                jump_number ++; 
                cur = max_reach;
            }
            
        }
        return jump_number;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */

