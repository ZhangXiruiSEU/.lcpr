/*
 * @lc app=leetcode id=503 lang=cpp
 * @lcpr version=30307
 *
 * [503] Next Greater Element II
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
                vector<int> res(nums.size());
        stack<int> s;
        for (int i = 2* nums.size()-1;i>=0;i--){
            while (!s.empty()&&nums[i%nums.size()]>=s.top()){
                s.pop();
            
            }
            res[i%nums.size()] = s.empty()?-1:s.top();
            s.push(nums[i%nums.size()]);
        }
        return res;
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,3]\n
// @lcpr case=end

 */

