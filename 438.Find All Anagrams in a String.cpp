/*
 * @lc app=leetcode id=438 lang=cpp
 * @lcpr version=30400
 *
 * [438] Find All Anagrams in a String
 */
#include "lc.h"
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>
// @lc code=start
class Solution
{
  public:
    vector<int> findAnagrams_encode(string s, string p)
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
        for (int i = 0; i < s.size(); i++)
        {
            auto temStr = s.substr(i, p.size());
            if (encode(temStr) == p_coded)
            {
                res.push_back(i);
            }
        }
        return res;
    }
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> demand_mp;
        for (auto &ch : p)
        {
            demand_mp[ch]++;
        }
        int left = 0;
        int right = 0;
        int required = p.size();
        vector<int> res;

        while (right < s.size())
        {
            auto chR = s[right];
            if (demand_mp.count(chR))
            {

                demand_mp[chR]--;
                if (demand_mp[chR] >= 0)
                    required--;
            }
            right++;
            if (right - left >= p.size())
            {
                if (required == 0)
                {
                    res.push_back(left);
                }
                auto chL = s[left];
                if (demand_mp.count(chL))
                {

                    demand_mp[chL]++;
                    if (demand_mp[chL] > 0)
                        required++;
                }
                left ++;
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
