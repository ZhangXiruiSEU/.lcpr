/*
 * @lc app=leetcode id=567 lang=cpp
 * @lcpr version=30400
 *
 * [567] Permutation in String
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    bool checkInclusion(string s1, string s2)
    {
        // 如果更快也可以双哈希表滑动窗口
        // 当成异位词问题
        auto encode = [&](string s) {
            wstring ws(26, 0);
            for (auto &ch : s)
            {
                ws[ch - 'a']++;
            }
            return ws;
        };
        auto coded1 = encode(s1);
        for (int i=0;i<s2.size();i++){
            auto coded2 = encode(s2.substr(i,s1.size()));
            if (coded2==coded1) return true;
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ab"\n"eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"eidboaoo"\n
// @lcpr case=end

 */
