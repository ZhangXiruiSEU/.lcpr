/*
 * @lc app=leetcode id=26 lang=cpp
 * @lcpr version=30304
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while (fast<nums.size()){
            if (nums[fast]!= nums[slow]){
                slow ++;
                nums[slow] = nums[fast];
            }
            
            fast +=1;

        }
        return slow+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */

