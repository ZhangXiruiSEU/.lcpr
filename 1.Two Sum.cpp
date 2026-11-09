/*
 * @lc app=leetcode id=1 lang=cpp
 * @lcpr version=30400
 *
 * [1] Two Sum
 */
#include "lc.h"
#include <unordered_map>
#include <vector>
// @lc code=start
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 2 pointers
        vector<vector<int>> numWithIndx;
        for (int i = 0; i < nums.size(); i++)
        {
            numWithIndx.push_back({nums[i], i});
        }

        std::sort(numWithIndx.begin(), numWithIndx.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            auto temSum = numWithIndx[left][0] + numWithIndx[right][0];
            if (temSum > target)
            {
                right--;
            }
            else if (temSum < target)
            {
                left++;
            }
            else
            {
                return {numWithIndx[left][1], numWithIndx[right][1]};
            }
        }
        throw;
    }
    vector<int> twoSum_hash(vector<int> &nums, int target)
    {
        // hash
        unordered_map<int, int> hash;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];       // count the complementary number
            if (hash.find(complement) == hash.end()) // if not visited yet
            {
                hash[nums[i]] = i; // ??? record the indx of the num?
            }
            else // if we found the complement
            {
                res = {i, hash[complement]};//ok w
                break;
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
