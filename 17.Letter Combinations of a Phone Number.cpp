/*
 * @lc app=leetcode id=17 lang=cpp
 * @lcpr version=30400
 *
 * [17] Letter Combinations of a Phone Number
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> mapping = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                               {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> res;
        string resTemp;
        auto backtrack = [&](auto&& self,int start) {
            if (resTemp.size()==digits.size()){
                res.push_back(resTemp);
                //resTemp.clear();
                return;

            }
                

            for (auto& ch:mapping[digits[start]]){
                resTemp+=ch;
                self(self,start+1);
                resTemp.resize(start);

            }
        };
        backtrack(backtrack,0);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
    // 每个数字到字母的映射

    vector<string> res;
    string sb;

  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return res;
        }
        // 从 digits[0] 开始进行回溯
        backtrack(digits, 0);
        return res;
    }

    // 回溯算法主函数
    void backtrack(const string &digits, int start)
    {
        if (sb.size() == digits.size())
        {
            // 到达回溯树底部
            res.push_back(sb);
            return;
        }

        // 回溯算法框架
        char digit = digits[start];
        for (char c : mapping[digit])
        {
            // 做选择
            sb.push_back(c);
            // 递归下一层回溯树
            backtrack(digits, start + 1);
            // 撤销选择
            sb.pop_back();
        }
    }
};