/*
 * @lc app=leetcode id=752 lang=cpp
 * @lcpr version=30307
 *
 * [752] Open the Lock
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> visited;
        unordered_set<string> dead;
        for (auto &s : deadends)
        {
            dead.insert(s);
        }
        queue<string> q;
        if (dead.count(string("0000"))) return -1;
        q.push(string("0000"));
        visited.insert(string("0000"));
        
        int step = 0;
        auto plus1 = [=](string s, int indx) {
            s[indx] = s[indx] - '0' + 1 > 9 ? 0 + '0' : s[indx] + 1;
            return s;
        };
        auto minus1 = [=](string s, int indx) {
            s[indx] = s[indx] - '0' - 1 < 0 ? 9 + '0' : s[indx] - 1;
            return s;
        };
        vector<string> neighbors;
        auto move = [&](string s) {
            neighbors.clear();
            for (int i = 0; i < 4; i++)
            {
                neighbors.push_back(minus1(s, i));
                neighbors.push_back(plus1(s, i));
            }
            return neighbors;
        };
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto cur = q.front();
                q.pop();
                if (cur == target)
                    return step;
                
                for (auto &s : move(cur))
                {
                    if (!visited.count(s) && !dead.count(s))
                    {
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["0201","0101","0102","1212","2002"]\n"0202"\n
// @lcpr case=end

// @lcpr case=start
// ["8888"]\n"0009"\n
// @lcpr case=end

// @lcpr case=start
// ["8887","8889","8878","8898","8788","8988","7888","9888"]\n"8888"\n
// @lcpr case=end

 */
