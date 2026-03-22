/*
 * @lc app=leetcode id=931 lang=cpp
 * @lcpr version=30307
 *
 * [931] Minimum Falling Path Sum
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> memo;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        memo.resize(n,vector<int>(n, numeric_limits<int>::max()));
        int res = numeric_limits<int>::max();
        for (int i=0;i<n;i++){
            res = min(res,dp(matrix,n-1,i));
        }
        return res;
    }

    int dp(const vector<vector<int>>& matrix, int i, int j){
        auto n = matrix.size();
        if(i<0||j<0||i>=n||j>=n) return numeric_limits<int>::max();
        if (i == 0) {
        return matrix[i][j];
        }
         if (memo[i][j] != numeric_limits<int>::max()) {
            return memo[i][j];
        }
        memo[i][j] =  min({dp(matrix,i-1,j),
        dp(matrix,i-1,j-1),
        dp(matrix,i-1,j+1)}) + matrix[i][j];
        
        return memo[i][j];
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,3],[6,5,4],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[-19,57],[-40,-5]]\n
// @lcpr case=end

 */

