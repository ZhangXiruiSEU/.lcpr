/*
 * @lc app=leetcode id=84 lang=cpp
 * @lcpr version=30400
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <stack>
class Solution
{
  public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        heights.push_back(0);
        int res{0};
        for (int i = 0; i < heights.size(); i++)
        {
            while (st.empty() &&)
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */
