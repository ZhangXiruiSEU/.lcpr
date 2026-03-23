/*
 * @lc app=leetcode id=41 lang=cpp
 * @lcpr version=30400
 *
 * [41] First Missing Positive
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        int i = 0;
        int res = nums.size() + 1;
        while (i < nums.size())
        {
            if (nums[i] <= nums.size() && nums[i] > 0 // 在范围内
            //&& nums[i] != i + 1                   // 而且也没归位(多余的)
                && nums[nums[i] - 1] != nums[i]       // 而且目标位置也没归位
            )
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else
            {
                i++;
            }
        }
        // cout<<res<<endl;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                res = i + 1;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */
