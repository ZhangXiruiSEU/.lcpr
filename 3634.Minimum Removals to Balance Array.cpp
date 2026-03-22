/*
 * @lc app=leetcode id=3634 lang=cpp
 * @lcpr version=30307
 *
 * [3634] Minimum Removals to Balance Array
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort (nums.begin(),nums.end());
        int   left=0, right=0,n=nums.size(),max_len=0;
        if (n==1) return 0;
        while (right < n){
            auto cur = nums[right];
            right++;
            while (left<right&& 1LL*nums[left]*k<cur){
                left++;
            }
            max_len = max(max_len,right-left);

        }
        return n-max_len;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,6,2,9]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4,6]\n2\n
// @lcpr case=end

 */

