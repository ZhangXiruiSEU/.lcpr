/*
 * @lc app=leetcode id=131 lang=cpp
 * @lcpr version=30401
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include <string>
#include <vector>
class Solution
{
  public:
    vector<vector<string>> partition(string s)
    {
        vector<string> solution;
        vector<vector<string>> res;
        auto backtrack = [&](auto &&self, int start) {
            if (start == s.size())
            {
                res.push_back(solution);
                return;
            }
            for (int i = start; i < s.size(); i++)
            {
                // i 是从哪里分割下来 假设 i=1  abc =》 ab  c
                if (isParlindrome(s, start, i))
                {
                    solution.push_back(s.substr(start, i - start + 1));
                    self(self, i + 1);
                    solution.pop_back();
                }
            }
        };
        backtrack(backtrack, 0);
        return res;
    }

    bool isParlindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */
