/*
 * @lc app=leetcode id=139 lang=cpp
 * @lcpr version=30400
 *
 * [139] Word Break
 */

// @lc code=start
#include <string>

class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        //unordered_set<string> st{wordDict.begin(),wordDict.end()};
        unordered_set<int> cannot_st;
        bool can_break = false;
        auto recur = [&](auto &self, int index) -> void {
            // 终止条件
            if (index == s.size())
            {
                can_break = true;
                return;
            }
            if (cannot_st.contains(index)) return; 


            // 从 index 开始找 dict 里面匹配的
            for (auto &word : wordDict)
            {
                
                if (can_break) break;
                if (s.size() - index < word.size())
                {
                    continue;
                }
                // s.substr() 慢
                if (s.compare(index, word.length(), word) == 0)
                {
                    
                    self(self, index + word.size());
                    if (can_break==false){
                        cannot_st.insert(index + word.size());
                    }
                }
            }
        };
        recur(recur, 0);
        return can_break;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "leetcode"\n["leet","code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple","pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats","dog","sand","and","cat"]\n
// @lcpr case=end

 */
