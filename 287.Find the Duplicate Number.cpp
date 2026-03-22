/*
 * @lc app=leetcode id=287 lang=cpp
 * @lcpr version=30400
 *
 * [287] Find the Duplicate Number
 */
#include "lc.h"
#include <unordered_set>
// @lc code=start
class Solution {
public:
int findDuplicate(vector<int>& nums){
    //这个数字范围就很特别
    //范围是 1-N，注意下标是 0-N
    int fast{};
    int slow{};
    while(slow==0 || slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];

    }
    slow =0;
    while (slow!=fast){
        slow = nums[slow];
        fast = nums[fast];

    }
    return slow;
}
    int findDuplicate_hash(vector<int>& nums) {
        unordered_set<int> st;
        int res{};
        for (auto & n :nums){
            if(st.insert(n).second==false)
            {
                res = n;
                return res;
            }
            
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,3,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3,3]\n
// @lcpr case=end

 */

