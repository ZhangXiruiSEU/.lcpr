/*
 * @lc app=leetcode id=31 lang=cpp
 * @lcpr version=30400
 *
 * [31] Next Permutation
 */
#include "lc.h"
#include <algorithm>
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //想象成一个整数，其实就是找下一个大一点点的数字
        //那就是从个位开始往高位找，在越低位操作越好
        bool isLast = true;
        for (int i = nums.size()-2;i>=0;i--){
            //情况 1  
            // 找到第一个有上升空间的数，
            // 找到第一个下降的数
            if(nums[i]<nums[i+1]){
                isLast =false;
                //去后面找到这个数字大的里面最小的
                int valueSwap = nums[i];
                for (int j=nums.size()-1;j>i;j--){
                    // 找到第一个比这个 i 小的那前一个就是满足条件
                    if (nums[j]>nums[i]){
                        swap(nums[j],nums[i]);
                        break;
                    }
                    
                }
                std::reverse(nums.begin()+i+1,nums.end());
                break;
            }
            
        }
        if (isLast){
            reverse(nums.begin(), nums.end());
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */

