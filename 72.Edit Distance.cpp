/*
 * @lc app=leetcode id=72 lang=cpp
 * @lcpr version=30307
 *
 * [72] Edit Distance
 */
#include "lc.h"
// @lc code=start
class Solution
{
    typedef string s;
    vector<vector<int>> memo;

public:
    int minDistance(string word1, string word2)
    {
        memo.resize(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return dp(word1,word2,word1.size()-1,word2.size()-1);
    }
    int dp(s w1, s w2, int i, int j)
    {
        // let me do backward

        if (i == -1 && j == -1)
            return 0;
        if (i == -1)
            return j + 1;
        if (j == -1)
            return i + 1;

        if (memo[i][j] != -1)
            return memo[i][j];
        if (w1[i] == w2[j])
            memo[i][j] = dp(w1, w2, i - 1, j - 1);
        else
        {
            memo[i][j] = min({dp(w1, w2, i - 1, j - 1) + 1,
                              dp(w1, w2, i - 1, j) + 1,
                              dp(w1, w2, i, j - 1) + 1});
        }

        return memo[i][j];
    }
};
// @lc code=end

/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */
