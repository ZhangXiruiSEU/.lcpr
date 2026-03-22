/*
 * @lc app=leetcode id=5 lang=cpp
 * @lcpr version=30304
 *
 * [5] Longest Palindromic Substring
 */
#include <string>
#include <algorithm>
using std::string, std::max;

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ret = "";
        for (int i = 0; i < s.size(); i++)
        {
            string s_odd = palindrome(s, i, i);
            string s_even = palindrome(s, i, i + 1);
            ret = std::max({s_odd, s_even, ret},
                           [](const string &x, const string &y)
                           {
                               return x.size() < y.size();
                           });
        }
        return ret;
    }
    std::string palindrome(std::string s, int l, int r)
    {
        // 防止索引越界
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            // 双指针，向两边展开
            l--;
            r++;
        }
        // 此时 s[l+1..r-1] 就是最长回文串
        return s.substr(l + 1, r - l - 1);
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
