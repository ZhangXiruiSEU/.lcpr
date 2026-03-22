/*
 * @lc app=leetcode id=496 lang=cpp
 * @lcpr version=30307
 *
 * [496] Next Greater Element I
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        // 1 find the indx of nums1 element in nums2
        unordered_map<int, int> mp;

        // 2 find the next greater element of nums2
        stack<int> s;
        vector<int> resNGE(nums2.size());
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && nums2[i] > s.top())
            {
                s.pop();
            }
            resNGE[i] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = resNGE[i];
        }
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            res[i] = mp[nums1[i]];
        }
        return res;
    }

};
// @lc code=end

/*
// @lcpr case=start
// [4,1,2]\n[1,3,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n[1,2,3,4]\n
// @lcpr case=end

 */
