/*
 * @lc app=leetcode id=78 lang=cpp
 * @lcpr version=30400
 *
 * [78] Subsets
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    // For 循环 + 恢复现场”的结构是回溯算法的万能模板
    //  它非常容易扩展（比如加剪枝条件、去重条件）。
    {
        vector<int> temp;
        vector<vector<int>> res;
        auto backtrack = [&](auto &&self, int indx) -> void {
            res.push_back(temp);

            for (int i = indx; i < nums.size(); i++)
            {
                temp.push_back(nums[i]);
                self(self, i + 1);
                temp.pop_back();
            }
        };
        backtrack(backtrack, 0);
        return res;
    }

    vector<vector<int>> subsets_diy(vector<int> &nums)
    {
        vector<int> temp;
        vector<vector<int>> res;
        int count = 0;

        auto backtrack = [&](auto &&self, int indx) {
            if (indx >= nums.size())
            {
                res.push_back(temp);
                return;
            }
            self(self, indx + 1);

            temp.push_back(nums[indx]);
            self(self, indx + 1);
            temp.pop_back();
        };
        backtrack(backtrack, 0);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
