/*
 * @lc app=leetcode id=5 lang=cpp
 * @lcpr version=30304
 *
 * [5] Longest Palindromic Substring
 */
#include <algorithm>
#include <string>
#include <vector>
using std::string, std::max;

// @lc code=start
class Solution
{
  public:
    string longestPalindrome_dp(string s)
    {
        // dp[i][j] 区间是否是回文串 定义是双闭区间吧
        // dp[i][j] = dp[i+1][j-1] && dp[i]==dp[j]
        int maxlen = 1;
        int indx_left = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = true;
        }
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (i + 1 <= j - 1)
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j]);
                if (dp[i][j])
                {
                    if (j - i + 1 > maxlen)
                    {
                        maxlen = j - i + 1;
                        indx_left = i;
                    }
                }
            }
        }
        return s.substr(indx_left, maxlen);
    }
    string longestPalindrome(string s)
    {
        string ret = "";
        auto palindrome = [&](int left, int right) {
            while (left >= 0 && right < (int)s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }
            return s.substr(left + 1, right - 1 - left);
        };
        auto cmp = [](string x, string y) { return x.size() < y.size(); };
        for (int i = 0; i < s.size(); i++)
        {
            // 可能是奇数偶数
            string s_odd = palindrome(i, i);
            string s_even = palindrome(i, i + 1);
            ret = std::max({s_odd, s_even, ret}, cmp);
        }
        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
