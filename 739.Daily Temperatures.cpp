/*
 * @lc app=leetcode id=739 lang=cpp
 * @lcpr version=30307
 *
 * [739] Daily Temperatures
 */
#include "lc.h"
#include <stack>
#include <vector>

// @lc code=start
class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> days(temperatures.size());
        // 记录下一个更高温还有多少天
        stack<int> s; // 单调栈
        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            // 如果说目前的温度比之前的高，之前的就 pop了
            while (!s.empty() && temperatures[i] >= temperatures[s.top()])
            {
                s.pop();
            }

            days[i] = s.empty()?0:s.top() - i;
            s.push(i);
        }
        return days;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */
