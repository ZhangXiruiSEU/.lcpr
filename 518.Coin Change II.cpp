/*
 * @lc app=leetcode id=518 lang=cpp
 * @lcpr version=30307
 *
 * [518] Coin Change II
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        
        memo.resize(coins.size()+1,vector<int>((amount+1),-1));
        return dp(coins, coins.size(),amount);
    }
    int dp(const vector<int>& coins, int coinTypes, int amount){
        //use coinTypes coinTypes coins, when amount = amount, 
        //the dp() return the combinations of this situation 
        if (coinTypes == 0 ) return 0;//if no coin is used, 0 combination
        if (amount == 0) return 1;//if total amount is 0, 1 combination
        if (amount <0 ) return 0;// if total amount < 0, 0 combination


        // if the situation is computed, then return directly;
        if (memo[coinTypes][amount]!= -1) return memo[coinTypes][amount];

        //
        memo[coinTypes][amount] = 
            dp(coins,coinTypes-1,amount)+//if we don't use the i-th coin type;
            dp(coins,coinTypes,amount-coins[coinTypes-1]);//if we use the i-th coin type;
            //eg  3 types, but the 3rd type is actually coins[2];

        return memo[coinTypes][amount]; 
     }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[1,2,5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */

