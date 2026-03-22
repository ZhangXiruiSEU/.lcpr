/*
 * @lc app=leetcode id=279 lang=cpp
 * @lcpr version=30400
 *
 * [279] Perfect Squares
 */
#include "lc.h"
#include <climits>
#include <cmath>
#include <vector>
// @lc code=start
class Solution
{
  public:
    int numSquares(int n)
    {
        vector<int> perfSq;
        for (int i = 1; i <= 100; i++)
        {
            perfSq.emplace_back(i * i);
        }
        vector<vector<int>> memo(n + 1, vector<int>(100, 0));
        for (int j = 0;j<100;j++){
            memo[1][j]= 1;
        }
        for (int i = 1; i <= n; i++)
        {
            memo[i][0] = i / 1;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < 100; j++)
            {
                int min_num = INT_MAX;
                auto count = i / perfSq[j];
                if (count>0)
                {
                    int case1 = memo[i - 1 * perfSq[j]][j] + 1;
                    min_num = min(min_num, case1);
                }
                int case2 = memo[i][j-1];
                min_num = min(min_num, case2);
                memo[i][j] = min_num;
            }
        }
        return memo[n][99];
    };

    int numSquares_recur(int n)
    {
        // 10e4 == 100^2
        //
        vector<int> perfSq;
        for (int i = 1; i <= 100; i++)
        {
            perfSq.emplace_back(i * i);
        }
        vector<vector<int>> memo(n + 1, vector<int>(101, -1));
        // 对于sum 如果用前 indx 个数字 【0，indx】，最小的数量是 dp
        auto dp = [&](auto &&self, int sum, int indx) {
            // boundary cases
            if (sum == 1)
            {
                return 1;
            }
            if (indx == 0)
            {
                return sum / perfSq[0];
            }
            if (memo[sum][indx] != -1)
                return memo[sum][indx];
            // 用了 indx 这个数字 多少次呢？  一次?
            // 理论上是越多越好吧，错！ 只能去一个一个试。
            int min_num = INT_MAX;
            auto count = sum / perfSq[indx];
            for (int i = 1; i <= count; i++)
            {
                int case1 = self(self, sum - i * perfSq[indx], indx) + i;
                min_num = min(min_num, case1);
            }

            // 没用
            int case2 = self(self, sum, indx - 1);
            min_num = min(min_num, case2);
            memo[sum][indx] = min(min_num, case2);
            return memo[sum][indx];
        };

        return dp(dp, n, 99);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */
