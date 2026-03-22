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
        vector<vector<int>> pair;
        for (int i = 0; i < nums.size(); i++)
        {
            pair.push_back({nums[i], i});
        }

        std::sort(pair.begin(), pair.end());
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;
        while (left < right)
        {
            int sum = pair[left][0] + pair[right][0];
            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                res = {pair[left][1], pair[right][1]};
                break;
            }
        }
        return res;
    }
    vector<int> twoSum_hash(vector<int> &nums, int target)
    {
        // hash
        unordered_map<int, int> hash;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (hash.find(complement) == hash.end())
            {
                hash[nums[i]] = i;
            }
            else
            {
                res = {i, hash[complement]};
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
