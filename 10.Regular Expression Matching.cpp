/*
 * @lc app=leetcode id=10 lang=cpp
 * @lcpr version=30400
 *
 * [10] Regular Expression Matching
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        auto dp = [&](auto &&self, int i, int j) {
            // s的前 i 个和p的前 j 个是否匹配
            //
            // . 好说，关键是*
            // x* 就比较特殊，可以代表 任意个x，包括 0
            // 所以我们得看 x 后一位是不是 *

            // 1  如果不是*  正常匹配
            //   ax
            //   ax
            // 2  如果是*   0 个 x
            //  ax*
            //  aa
            // 3   1  个 x
            // a*
            // aaaa
            // 4   2+ 个 x

            // todo 边界条件
            if (j < 0)
                // 1
                if (p[j + 1] != '*')
                {
                    // 正常匹配就行了
                    // 匹配上了，那取决于前面是不是匹配
                    if (s[i] == p[j] || p[j] == '.')
                    {
                        return self(self, i - 1, j - 1);
                    }
                    else
                    {
                        return false;
                    }
                }
                
            

                
        };
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aa"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"a*"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n".*"\n
// @lcpr case=end

 */
