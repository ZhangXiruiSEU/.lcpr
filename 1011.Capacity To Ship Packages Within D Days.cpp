/*
 * @lc app=leetcode id=1011 lang=cpp
 * @lcpr version=30400
 *
 * [1011] Capacity To Ship Packages Within D Days
 */
#include "lc.h" 

// @lc code=start

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0;
        int right=1;
        for (auto  w : weights){
            left = max(left,w);
            right += w;
        }
        while (left<right){
            int mid = left + (right-left)/2;
            if (get_days(weights,mid)<=days){
                right = mid;
            }
            else {
                left = mid +1;
            }
        }
        return left;
    }
    int get_days(vector<int>& weights,int cap){
        int bef=0,aft=0;
        int days = 0;
        for (auto  w : weights){
            aft += w;
            if (aft > cap) {
                days ++;
                aft = w;
            }

        }
        days++;
        return days;
    } 
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,4,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,1]\n4\n
// @lcpr case=end

 */

