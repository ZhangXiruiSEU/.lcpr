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
        unordered_map<string, vector<int>> map;

        //给所有字符串编码，符合条件的字符串会变成一样的字符串
        for (int i = 0; i < strs.size(); i++)
        {
            string encoder(26,0);
            for (auto &l : strs[i])
            {
                encoder[l - 'a'] ++;
            }
            // 把每个编码的字符串序号都找到
            map[encoder].push_back(i);
        }
        //再根据哈希表输出结果就行了
        vector<vector<string>> res;
        for (auto &pair : map)
        {
            vector<string> resTemp;
            for (auto &indx : pair.second)
            {
                resTemp.push_back(strs[indx]);
            }

            res.push_back(resTemp);
        }
        return res;
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
