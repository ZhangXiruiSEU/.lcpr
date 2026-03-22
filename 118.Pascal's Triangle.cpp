/*
 * @lc app=leetcode id=118 lang=cpp
 * @lcpr version=30400
 *
 * [118] Pascal's Triangle
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
        {
            if (i == 0)
            {
                res.push_back({1});
                continue;
            }
            vector<int> cur(i + 1); // 第 i+1 行 有 i+1 个值

            for (int j = 0; j < i + 1; j++) 
            {
                int left, right;
                if (j == 0)
                    left = 0;
                else
                    left = res.back()[j - 1];
                if (j > i-1 )//上一行有 i 个值，j 最多也就 i-1
                    right = 0;
                else
                    right = res.back()[j];
                cur[j] = left + right;
            }
            res.push_back(cur);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
