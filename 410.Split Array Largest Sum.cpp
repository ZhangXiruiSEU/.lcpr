/*
 * @lc app=leetcode id=410 lang=cpp
 * @lcpr version=30307
 *
 * [410] Split Array Largest Sum
 */
#include "lc.h"
// @lc code=start
class Solution {
public:


    int splitArray(vector<int>& weights, int days) {
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
// [7,2,5,10,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

 */

