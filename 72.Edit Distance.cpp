/*
 * @lc app=leetcode id=72 lang=cpp
 * @lcpr version=30307
 *
 * [72] Edit Distance
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution
{
    typedef string s;
    vector<vector<int>> memo;

  public:
    int minDistance(string word1, string word2)
    {
        //  dp[i][j] word 1的前 i 个变为  word 2 的前 j 的距离，注意是前
        // i j 还是表示个数比较顺吧  那数组的大小就是+1 才能取到这个 i 个

        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        // 边界情况，所以如果 i 是 0 那就需要j 次  j是 0 就需要 i 次

        for (int j = 0; j <= word2.size(); j++)
        {
            dp[0][j] = j;
        }
        for (int i = 0; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        // index i-1 和 j-1
        // 相同 那就等于之前的 dp[i-1][j-1]
        // 如果增   dp[i][j-1] +1
        // 删  dp[i-1][j] +1
        // 改  dp[i-1][j-1] +1
        // 取最小值吧
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min({dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1});
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
    int minDistance_(string word1, string word2)
    {
        memo.resize(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return dp(word1, word2, word1.size() - 1, word2.size() - 1);
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
            memo[i][j] = min({dp(w1, w2, i - 1, j - 1) + 1, dp(w1, w2, i - 1, j) + 1, dp(w1, w2, i, j - 1) + 1});
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
