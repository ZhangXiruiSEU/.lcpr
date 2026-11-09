/*
 * @lc app=leetcode id=76 lang=cpp
 * @lcpr version=30304
 *
 * [76] Minimum Window Substring
 */
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
using std::string;
// @lc code=start
class Solution
{
  public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need;
        for (auto &ch : t)
        {
            need[ch]++;
        }
        int left = 0, right = 0;
        int required = t.size();
        int minWin = INT_MAX;
        int resL = 0;
        while (right < s.size())
        {
            auto curCh = s[right];
            // if (need[curCh] > 0)
            // {
            //     required--;
            // }
            need[curCh]--;
            right++;
            auto valid = [&]() {
                for (auto &[ch, cnt] : need)
                {
                    if (cnt > 0)
                        return false;
                }
                return true;
            };
            while (valid())
            {
                if (right - left < minWin)
                {
                    minWin = right - left;
                    resL = left;
                }
                need[s[left]]++;
                // if (need[s[left]] > 0)
                //     required++;
                left++;
            }
        }
        return minWin == INT_MAX ? "" : s.substr(resL, minWin);
    }
    string minWindow_2hash(string s, string t)
    {

        // 1 记录窗口中的数据

        // 需要的字符串的多少的记录，现在的情况
        std::unordered_map<char, int> demandList, curList;
        // 由于可能有重复的字符所以必须用 map 记录num，先记录需要的
        for (auto &tch : t)
        {
            demandList[tch]++;
        }
        int requireKind = demandList.size();
        int minWin = INT_MAX;
        int resL = 0;
        int left = 0, right = 0;

        // 模板
        while (right < s.size())
        {
            // 首先 记录即将加入窗口的值
            auto chR = s[right];
            // 如果说是我需要的
            if (demandList.count(chR))
            {
                // 记录进去
                curList[chR]++;
                // 如果说满足了这个字符的需要
                if (demandList[chR] == curList[chR])
                {
                    requireKind--;
                }
            }
            // 增大窗口
            right++;

            // 判断是否需要缩小窗口 当所有需要的都被满足
            while (requireKind == 0)
            {
                // 记录最小窗口的大小
                if (right - left < minWin)
                {
                    minWin = right - left;
                    resL = left;
                }
                // 即将出窗口的值
                auto chL = s[left];
                // 如果说属于我们需要的
                if (demandList.count(chL))
                {
                    // 如果说本来满足需要了
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
