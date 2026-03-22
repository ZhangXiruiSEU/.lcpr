/*
 * @lc app=leetcode id=32 lang=cpp
 * @lcpr version=30400
 *
 * [32] Longest Valid Parentheses
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        int curLen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    // 如果弹完发现栈空了，说明刚才弹出的不是左括号，而是旧的哨兵
                    // 说明当前这个 ')' 是多余的，它成为了新的“最后边界”
                    st.push(i);
                }
                else
                {
                    // 如果弹完栈不空，说明刚才匹配成功了！
                    // 有效长度 = 当前下标 - 此时的新栈顶下标
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */
