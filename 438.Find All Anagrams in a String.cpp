/*
 * @lc app=leetcode id=438 lang=cpp
 * @lcpr version=30400
 *
 * [438] Find All Anagrams in a String
 */
#include "lc.h"
#include <bitset>
#include <string>
// @lc code=start
class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        
        auto encode = [&](string stemp) {
            vector<int> encoder(26, 0);
            for (auto &pChar : stemp)
            {
                encoder[pChar - 'a']++;
            }
            return encoder;
        };
        auto p_coded = encode(p);
        vector<int> res;
        for (int i = 0;i < s.size();i++){
            auto temStr = s.substr(i,p.size());
            if (encode(temStr)==p_coded){
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */
