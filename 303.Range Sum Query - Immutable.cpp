/*
 * @lc app=leetcode id=303 lang=cpp
 * @lcpr version=30307
 *
 * [303] Range Sum Query - Immutable
 */
#include "lc.h"
// @lc code=start
class NumArray {
    vector<int> presum;
public:
    NumArray(vector<int>& nums) {
        presum.reserve(nums.size()+1);
        int tempSum = 0;
        for (int i=0;i<nums.size()+1;i++){
            presum[i] = tempSum;
            if(i!=nums.size())
            tempSum+=nums[i];
            //this, i-indx means the sum of before i
            
        }
        
    }
    
    int sumRange(int left, int right) {
        return presum[right+1]-presum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]\n
// @lcpr case=end

 */

