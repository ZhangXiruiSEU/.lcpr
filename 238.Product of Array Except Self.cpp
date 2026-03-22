/*
 * @lc app=leetcode id=238 lang=cpp
 * @lcpr version=30400
 *
 * [238] Product of Array Except Self
 */
#include "lc.h"
#include <cstdint>
#include <vector>
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int32_t> res(nums.size(),1);
        int32_t curPro  =1;

        //now it is the product before
        for (int i = 1;i<nums.size();i++){
            curPro*=nums[i-1];
            res[i] = curPro;
        }
        curPro = 1;
        for (int i = nums.size()-2;i>=0;i--){
            curPro*=nums[i+1];
            res[i] *=curPro;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */

