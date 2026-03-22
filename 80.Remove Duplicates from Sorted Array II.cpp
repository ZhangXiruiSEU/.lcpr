/*
 * @lc app=leetcode id=80 lang=cpp
 * @lcpr version=30400
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
#include <unordered_map>
#include <vector>
class Solution
{
  public:
    int removeDuplicates(std::vector<int> &nums)
    {
        if (nums.size()<=2) return nums.size();
        //std::unordered_map<int, int> mp;
        int fast = 2;
        int slow = 2;
        //int count = 0;
        for (; fast < nums.size(); fast++)
        {
            if(nums[fast]!=nums[slow-2]){
                nums[slow]=nums[fast];
                slow ++;
            }
        }
        return slow;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */
