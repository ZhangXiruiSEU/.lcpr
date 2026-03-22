/*
 * @lc app=leetcode id=75 lang=cpp
 * @lcpr version=30400
 *
 * [75] Sort Colors
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto myswap = [&](int indx1, int indx2){
            int temp = nums[indx1];
            nums[indx1] =  nums[indx2];
             nums[indx2] =  temp;
        };
        int p0=0;//左闭右开 0-p0
        int i=0; //p0-i 是 1
        int p2=nums.size(); //p2 到 size是 2
        while (i<p2){
            if( nums[i] == 0) {
                p0 ++;                
                myswap(i,p0-1);
                i++;
            }

            else if( nums[i] == 2) {
                p2--;
                myswap(i,p2);               
            }
            else i++;

        }
        return;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

