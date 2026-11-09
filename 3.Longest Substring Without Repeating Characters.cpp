/*
 * @lc app=leetcode id=3 lang=cpp
 * @lcpr version=30400
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include "lc.h"
#include <unordered_map>
#include <unordered_set>
// @lc code=start
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<int> set;
        int left = 0, right = 0; // 滑动窗口模板是左闭右开
        int maxLen = 0;
        // 按模板来 的话 right 就不要 while 里面移动
        while (right < s.size())
        {
            while (set.count(s[right]) == 1)
            {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            right++;
            maxLen = max (maxLen,right-left);
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
