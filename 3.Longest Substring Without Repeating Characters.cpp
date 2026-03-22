/*
 * @lc app=leetcode id=3 lang=cpp
 * @lcpr version=30400
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include "lc.h"
#include <unordered_set>
// @lc code=start
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<int> st;
        int left = 0;
        int maxLen = 0;
        int right = 0;
        while (right < s.size())
        {
            auto chR = s[right];
            right++;//right是下一个待操作的位置
            //如果能插就插
            if (st.count(chR) == 0)
            {
                st.insert(chR);
            }
            //但是本位置还没有操作，so far
            else
            {
                // 如果说还是进不去，那就左边移动
                while (st.count(chR) == 1)
                {
                    auto chL = s[left];
                    left++;
                    st.erase(chL);
                }
                //直到可以进去
                st.insert(chR);// 终于操作了
            }
            maxLen = max(maxLen,right-left);
        }
        return maxLen;
    }
    int lengthOfLongestSubstring_old(string s)
    {
        unordered_set<int> st;
        int left = 0;
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        { // 右侧是即将要加入窗口的哦
            // 如果要出现重复了 记录最大值
            if (st.count(s[i]) == 1)
            {
                maxLen = max((int)st.size(), maxLen);
            }

            // 左移，一直到重复消失
            while (left < i && st.count(s[i]) == 1)
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
        }
        maxLen = max((int)st.size(), maxLen);
        return maxLen;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
