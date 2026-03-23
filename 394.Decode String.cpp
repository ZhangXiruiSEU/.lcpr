/*
 * @lc app=leetcode id=394 lang=cpp
 * @lcpr version=30400
 *
 * [394] Decode String
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <string>
#include <utility>
class Solution
{
  public:
    // 标准写法，还是很绕，反正记住就行了
    string decodeString(string s)
    {
        stack<string> strSt;
        stack<int> countSt;
        int count = 0;
        string str;

        for (auto &ch : s)
        {
            if (ch <= '9' && ch >= '0')
            {

                count = count * 10 + ch - '0';
            }
            else if (ch == '[')
            {
                //
                strSt.push(str);
                str.clear();
                //
                countSt.push(count);
                count = 0;
            }
            else if (ch == ']')
            {
                auto curCount = countSt.top();
                countSt.pop();
                string prevStr = strSt.top();
                strSt.pop();
                for (int i = 0; i < curCount; i++)
                {
                    prevStr += str;
                }
                str = prevStr;
            }
            else
            {
                str.push_back(ch);
            }
        }
        return str;
    }

    // 非常糙的递归写法，细节太多，不推荐深挖
    string decodeString_old(string s)
    {
        auto recur = [&](auto &self, int start) -> pair<string, int> {
            // string timesStr;
            string res;
            int endIndx = 0;
            for (int i = start; i < s.size(); i++)
            {
                int times = 0;
                if (s[i] <= '9' && s[i] >= '0')
                {

                    while (s[i] <= '9' && s[i] >= '0')
                    {

                        times = times * 10 + s[i] - '0';
                        i++;
                    }
                    auto [str, end] = self(self, i + 1); // 跳过那个括号
                    i = end;                             // 注意循环自动加一
                    for (int j = 0; j < times; j++)
                    {
                        res += str;
                    }
                }
                else if (s[i] == ']')
                {
                    endIndx = i;
                    break;
                }
                else
                {
                    res += s[i];
                }
            }
            return {res, endIndx};
        };
        auto [str, end] = recur(recur, 0);
        return str;
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
