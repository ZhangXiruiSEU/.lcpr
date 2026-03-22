/*
 * @lc app=leetcode id=739 lang=cpp
 * @lcpr version=30307
 *
 * [739] Daily Temperatures
 */
#include "lc.h"

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> s;
        for (int i = temperatures.size()-1;i>=0;i--){
            while (!s.empty()&&temperatures[i]>=temperatures[s.top()]){
                s.pop();
            
            }
            res[i] = s.empty()?0:s.top()-i;
            s.push(i);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */

