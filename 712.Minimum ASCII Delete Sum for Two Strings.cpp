/*
 * @lc app=leetcode id=712 lang=cpp
 * @lcpr version=30307
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */
#include "lc.h"

// @lc code=start

class Solution
{
  public:
    string text1;
    string text2;
    vector<vector<int>> memo;
    int minimumDeleteSum(string text1, string text2)
    {
        this->text1 = text1;
        this->text2 = text2;
        memo.resize(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return dp(text1.size(), text2.size());
    }
    int dp(int i, int j)
    {
        if (memo[i][j] != -1)
            return memo[i][j];
        
        if (i == 0)
        {
            int res = 0;
            for (int k = 0; k < j; ++k) 
                res += text2[k];
            memo[i][j]= res;
            return res;
        }
        if (j == 0)
        {
           int res = 0;
            for (int k = 0; k < i; ++k) 
                res += text1[k];
                memo[i][j]= res;
            return res;
        }

        if (text1[i - 1] == text2[j - 1])
            memo[i][j] = dp(i - 1, j - 1);
        else
            memo[i][j] = min({dp(i - 1, j)+text1[i - 1], dp(i, j - 1)+text2[j - 1]});
        return memo[i][j];
    }
};
// @lc code=end

/*
// @lcpr case=start
// "sea"\n"eat"\n
// @lcpr case=end

// @lcpr case=start
// "delete"\n"leet"\n
// @lcpr case=end

 */
