/*
 * @lc app=leetcode id=76 lang=cpp
 * @lcpr version=30304
 *
 * [76] Minimum Window Substring
 */
#include <climits>
#include <string>
#include <unordered_set>
using std::string;
// @lc code=start
class Solution
{
  public:
    string minWindow(string s, string t)
    {
        std::unordered_map<char, int> demandList, curList;
        for (auto &tch : t)
        {
            demandList[tch]++;
        }
        int requireKind = demandList.size();
        int left = 0, right = 0;
        int minWin = INT_MAX;
        int resL{};
        while (right < s.size())
        {
            auto chR = s[right];
            if (demandList.count(chR))
            {
                curList[chR]++;
                if (demandList[chR] == curList[chR])
                {
                    requireKind--;
                }
            }
            right++;

            while (requireKind == 0)
            {
                if (right - left < minWin)
                {
                    minWin = right - left;
                    resL = left;
                }
                auto chL = s[left];
                if (demandList.count(chL))
                {
                    if (demandList[chL] == curList[chL])
                    {
                        requireKind++;
                    }
                    curList[chL]--;
                }
                left++;
            }
        }
        return minWin == INT_MAX ? "" : s.substr(resL, minWin);
    }
    string minWindow_singleHash(string s, string t)
    {
        // 哈希表记录我们需要的字符
        std::unordered_map<char, int> mp;
        for (auto &tch : t)
        {
            mp[tch]++;
        }

        // 肯定是滑动窗口

        //  减小窗口，就是在全部出现的时候来减小，减小到有效字符之前
        //  记录最短的大小，只要窗口有全部的t 元素，更新
        int require = t.size();
        int minWin = INT_MAX;
        int left{};
        int right{};
        int resL{};
        bool found = false;
        while (right < s.size())
        {
            auto chR = s[right];

            // 如果是目标字符
            if (mp.count(chR) == 1)
            {
                // 如果需求量还是正，需求--
                if (mp[chR] > 0)
                    require--;
                // 我需要的字符减少
                mp[chR]--;
            }
            //  增加窗口 每次都增
            right++;

            // 发现已经全部满足
            while (require == 0)
            {
                found = true;
                // 更新结果
                if (right - left < minWin)
                {
                    minWin = right - left;
                    resL = left;
                }
                auto chL = s[left];
                // 如果左边界的是目标字符
                if (mp.count(chL) == 1)
                {
                    // 如果说需求量大于等于零，丢了一个自然需求++
                    if (mp[chL] >= 0)
                        require++;
                    // 该字符需求量就增加
                    mp[chL]++;
                }
                left++;
            }
        }
        if (found)
            return s.substr(resL, minWin);
        else
            return "";
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */
