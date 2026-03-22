/*
 * @lc app=leetcode id=583 lang=cpp
 * @lcpr version=30307
 *
 * [583] Delete Operation for Two Strings
 */
#include "lc.h"
// @lc code=start
class Solution {
                string text1;
    string text2;
    vector<vector<int>> memo;
public:
    int minDistance(string word1, string word2) {
        this->text1 = word1;
        this->text2 = word2;
        memo.resize(text1.size()+1,vector<int>(text2.size()+1,-1));
        return dp(text1.size(),text2.size());
    }
    int dp(int i,int j){
        if (i==0) return j;
        if (j==0) return i;

        if (memo[i][j] != -1)return memo[i][j];
        if (text1[i-1]==text2[j-1])
            memo[i][j] = dp(i-1,j-1);
            else
        memo[i][j] =  min({dp(i-1,j)+1,dp(i,j-1)+1});
        return memo[i][j] ;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sea"\n"eat"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"etco"\n
// @lcpr case=end

 */

