/*
 * @lc app=leetcode id=322 lang=cpp
 * @lcpr version=30304
 *
 * [322] Coin Change
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo (amount+1,-2);
        //return dp(coins,amount,memo);
        return dp_array(coins,amount);
    }
    int dp(vector<int>& coins, int amount,vector<int>& memo) {
        
        int res = INT_MAX;
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (memo[amount] != -2) return memo[amount];
        for (const int coin: coins){
            int sub = dp(coins,amount - coin,memo);
            if (sub == -1) continue;
            
            res = min(res, sub+1);
            

        }
        memo[amount]= (res == INT_MAX? -1 :res);
        return memo[amount];
    }

    int dp_array(vector<int>& coins, int amount){
        vector<int> dp(amount + 1, amount + 100);
        dp[0]=0;//dp[i],when the hell the target amout is i, the minimum numbers of coins is dp[i]
        for (int i = 0;i<dp.size();i++){
            for (const int c:coins){
                if (i-c<0) continue;
                dp[i] = min (dp[i],1+dp[i-c]);
            }
        }
        return (dp[amount] == amount + 100) ? -1 : dp[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

