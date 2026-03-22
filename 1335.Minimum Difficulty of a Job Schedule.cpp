/*
 * @lc app=leetcode id=1335 lang=cpp
 * @lcpr version=30307
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> memo;

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memo.resize(jobDifficulty.size()+1,vector<int>(d+1,-999));
        return dp(jobDifficulty,jobDifficulty.size(),d);
    }
    int dp(vector<int>& jobDifficulty, int jobs, int d){
        //前 d 天，完成前 jobs 个工作
        if (jobs < d) return -1;
        if (d ==0&&jobs>0) return -1;
        if (d == 0 && jobs==0) return 0;

        if(memo[jobs][d]!=-999) return memo[jobs][d];
        int min_res = INT_MAX;
        int cur_max = 0;
        for (int i=1;i<=jobs;i++){ 
            int res = dp(jobDifficulty,jobs-i,d-1);
            cur_max = max(cur_max,jobDifficulty[jobs-i]);
            if (res!=-1)
            {
                //res += *max_element(jobDifficulty.begin() + jobs-i,jobDifficulty.begin() + jobs);
                res+= cur_max;
                if (res<min_res) {
                min_res = res;
                }
            } 
        }
        if (min_res == INT_MAX)
        memo[jobs][d] = -1;
        else  memo[jobs][d] = min_res;
        return  memo[jobs][d];
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,5,4,3,2,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n3\n
// @lcpr case=end

 */

