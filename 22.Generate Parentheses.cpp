/*
 * @lc app=leetcode id=22 lang=cpp
 * @lcpr version=30400
 *
 * [22] Generate Parentheses
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution
{
  public:
    // 回溯 关键还是一个函数内部能尝试多种选择

    vector<string> generateParenthesis(int n)
    {
        string solution;
        vector<string> res;
        int leftnum = n;
        int rightnum = n;
        auto backtrack = [&](auto &self) {
            if (leftnum > rightnum)
            {
                return;
            }
            if (leftnum == 0 && rightnum == 0)
            {
                res.push_back(solution);
                return;
            }
            if (leftnum)
            {
                leftnum--;
                solution += '(';
                self(self);
                solution.pop_back();
                leftnum++;
            }

            if (rightnum)
            {
                rightnum--;
                solution += ')';
                self(self);
                solution.pop_back();
                rightnum++;
            }
        };
        backtrack(backtrack);
        return res;
    }

    // dp写法比回溯难想的多，现在也没写对，没必要深究了
    vector<string> generateParenthesis_dp(int n)
    {
        vector<vector<string>> memo(9, vector<string>(0));
        auto dp = [&](auto &self, int i) -> vector<string> {
            if (i == 1)
            {
                return {"()"};
            }

            if (!memo[i].empty())
                return memo[i];

            for (auto &str : self(self, i - 1))
            {
                memo[i].push_back(str + "()");
                memo[i].push_back("(" + str + ")");
            }
            return memo[i];
        };
        return dp(dp, n);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
