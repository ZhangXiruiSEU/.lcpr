/*
 * @lc app=leetcode id=416 lang=cpp
 * @lcpr version=30307
 *
 * [416] Partition Equal Subset Sum
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
vector<vector<char>> memo;
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (const auto& n:nums) sum+=n;
        if (sum%2!=0) return false;
        sum/=2;


        memo.resize(nums.size()+1, vector<char>(sum + 1, -1));//-1 means undefined
        
        return dp(nums,nums.size()-1,sum);

    }
    bool dp(vector<int>& nums,int i, int sum)
    {
        if (sum == 0) return true;
        if (sum< 0||i<0) return false;
        //boundary condition 

        //check the memo
        if (memo[i][sum]!=-1) return memo[i][sum];
        auto res = dp(nums,i-1,sum)//whether i-th is useless 
        ||dp(nums,i-1,sum-nums[i]);// or with i, perfectly filled, which means
        //without i ,sum-nums[i] can also be perfectly filled
        
        memo[i][sum]= res;
        return res;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */

