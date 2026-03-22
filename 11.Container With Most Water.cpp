/*
 * @lc app=leetcode id=11 lang=cpp
 * @lcpr version=30400
 *
 * [11] Container With Most Water
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        // 暴力TLE
        int area = 0;
        // for (int i = 0;i<height.size()-1;i++) {
        //     for (int j = i+1;j<height.size();j++){
        //         int curArea  = min(height[i],height[j]) *( j-i);
        //         area = max(area,curArea);
        //     }
        // }
        // 贪心的思路，先把宽度拉满，相当于左右指针往里走
        // 那找最大值其实就是必须要
        int i = 0, j = height.size() - 1;
        while (i < j)
        {

            int curH = min(height[i], height[j]);
            int curArea = curH * (j - i);
            area = max(area, curArea);
            // 只有移动短板才有可能增加面积
            // 移动长板不增加面积 ，
            if (height[i]<height[j])// i 是短板
            {
                i++;
            }
            else{
                j--;
            }
        }
        
        return area;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */
