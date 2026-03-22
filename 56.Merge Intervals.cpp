/*
 * @lc app=leetcode id=56 lang=cpp
 * @lcpr version=30400
 *
 * [56] Merge Intervals
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result = {intervals[0]};
        
        for (auto& interval:intervals){
            if (interval.front()>result.back().back()){
                result.emplace_back(interval);
                
            }
            
            else if (interval.back()>result.back().back()){
                result.back().back() = interval.back();
            }
        }
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,7],[1,4]]\n
// @lcpr case=end

 */

