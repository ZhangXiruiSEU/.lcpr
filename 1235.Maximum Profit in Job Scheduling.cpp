/*
 * @lc app=leetcode id=1235 lang=cpp
 * @lcpr version=30400
 *
 * [1235] Maximum Profit in Job Scheduling
 */
#include "lc.h"
#include <functional>
#include <map>
#include <unordered_map>
#include <vector>
// @lc code=start
class Solution
{
  public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<int> memo(startTime.size(),-1);
        vector<vector<int>> jobs(startTime.size());
        for (int i = 0; i < startTime.size() ; ++i) {
            // 重点：一定要按 endTime 排序！
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        std::map<int, int> endtime_profit;
        endtime_profit[0] = 0;
        endtime_profit[1] = 0;

        // 0-1 bag:
        // dp( i  w )   first i item,  w is the capacity , dp() is the max value
        // now dp (i)
        function<int(int)> dp = [&](int i) -> int {
            if(memo[i]!=-1) return memo[i];
            if (i == 0)
            {
                endtime_profit[jobs[i][0]] = jobs[i][2];
                memo[i] = jobs[i][2];
                return jobs[i][2];
            }

            int res = max(dp(i - 1), jobs[i][2]+ prev(endtime_profit.upper_bound(jobs[i][1]))->second);
            endtime_profit[jobs[i][0]] = res;
            memo[i] = res;
            return res;
        };
        return dp(startTime.size() - 1);

    } //
}

;
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,6]\n[3,5,10,6,9]\n[20,20,100,70,60]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[2,3,4]\n[5,6,4]\n
// @lcpr case=end

 */
