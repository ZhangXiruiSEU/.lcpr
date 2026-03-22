/*
 * @lc app=leetcode id=242 lang=cpp
 * @lcpr version=30400
 *
 * [242] Valid Anagram
 */
#include "lc.h"
#include <cstddef>
#include <string>
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size())return false;
        size_t n = s.size();
        auto encode = [&](string s){
            wstring ws(26,0);
            for (auto & ch :s){
                ws[ch-'a']++;
            }
            return ws;
        };
        if (encode(s)==encode(t)) return true;
        else return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */

