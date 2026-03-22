/*
 * @lc app=leetcode id=42 lang=cpp
 * @lcpr version=30400
 *
 * [42] Trapping Rain Water
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int contain = 0;

        //某个索引能接的水其实就是
        // （左边最大值和右边最大值）的最小值，再减去索引位置的高度，当然最小只能是 0
        //直接遍历来记录这个左边和右边最大值

        vector<int> lm(height.size(), -1);
        vector<int> rm(height.size(), -1);
        int leftMax = 0;
        int rightMax = 0;
        // 注意索引边界
        for (int i = 0; i < height.size()-1; i++){
            leftMax = max(leftMax, height[i]);
            lm[i+1] = leftMax;
        }
        for (int i = height.size()-1; i >=1; i--){
            rightMax = max(rightMax, height[i]);
            rm[i-1] = rightMax; 
        }
        // 
        for (int i = 0; i < height.size(); i++)
        {

            int curVol = min(lm[i], rm[i]) - height[i];
            contain += curVol > 0 ? curVol : 0;
            // cout<<contain<<endl;
        }
        return contain;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
