/*
 * @lc app=leetcode id=49 lang=cpp
 * @lcpr version=30400
 *
 * [49] Group Anagrams
 */
#include "lc.h"
#include <array>
#include <string>
#include <unordered_map>
// @lc code=start
class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 字符串到数组的哈希表
        unordered_map<string, vector<string>> map;

        // 给所有字符串编码，符合条件的字符串会变成一样的字符串
        for (auto &str : strs)
        {
            string encoder(26, 0);
            for (auto &ch : str)
            {
                encoder[ch - 'a']++;
            }
            map[encoder].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto kv : map)
        {
            ans.push_back(kv.second);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["eat","tea","tan","ate","nat","bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */
