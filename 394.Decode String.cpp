/*
 * @lc app=leetcode id=394 lang=cpp
 * @lcpr version=30400
 *
 * [394] Decode String
 */

// @lc code=start
#include <cctype>
#include <stack>
#include <string>
class Solution
{
  public:
    std::string decodeString(std::string s)
    {
        std::stack<int> counts;
        std::stack<std::string> prefixes;
        std::string cur;
        int num = 0;

        for (char ch : s)
        {
            if (std::isdigit(static_cast<unsigned char>(ch)))
            {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[')
            {
                counts.push(num);
                prefixes.push(cur);
                num = 0;
                cur.clear();
            }
            else if (ch == ']')
            {
                int repeat = counts.top();
                counts.pop();

                std::string decoded = prefixes.top();
                prefixes.pop();
                while (repeat--)
                {
                    decoded += cur;
                }
                cur = decoded;
            }
            else
            {
                cur += ch;
            }
        }

        return cur;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "3[a]2[bc]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

 */
