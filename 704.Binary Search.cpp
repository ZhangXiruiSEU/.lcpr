/*
 * @lc app=leetcode id=704 lang=cpp
 * @lcpr version=30305
 *
 * [704] Binary Search
 */

#include "lc.h"

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            int mid = left + (right-left)/2;
            if (nums[mid]==target){
                return mid;
            }
            else if (nums[mid]<target){
                left = mid+1;
            }
            else if (nums[mid]>target){
                right =  mid -1;
            }
            
        }
        return -1;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

 */

