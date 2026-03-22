/*
 * @lc app=leetcode id=1143 lang=cpp
 * @lcpr version=30307
 *
 * [1143] Longest Common Subsequence
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    string text1;
    string text2;
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;
        memo.resize(text1.size()+1,vector<int>(text2.size()+1,-1));
        return dp(text1.size()-1,text2.size()-1);
    }
    int dp(int i, int j){
        if(i==-1 || j==-1) return 0;


        if (memo[i][j] != -1)return memo[i][j];
        if (text1[i]==text2[j])
            memo[i][j] = dp(i-1,j-1)+1;
            else
        memo[i][j] =  max({dp(i-1,j),dp(i,j-1)});
        return memo[i][j] ;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */

