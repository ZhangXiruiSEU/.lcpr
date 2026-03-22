/*
 * @lc app=leetcode id=763 lang=cpp
 * @lcpr version=30400
 *
 * [763] Partition Labels
 */
#include "lc.h"
#include <unordered_set>
#include <vector>
// @lc code=start
class Solution
{
  public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> hash;
        // cout<<string("abcs").size()<<'\n';
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i]] = i;
        }
        vector<int> result;
        int start{};
        int end{};
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, hash[s[i]]);
            if (i == end)
            {
                result.push_back(end - start + 1);
                start = i + 1; // 下一个片段的开始
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ababcbacadefegdehijhklij"\n
// @lcpr case=end

// @lcpr case=start
// "eccbbbbdec"\n
// @lcpr case=end

 */
