/*
 * @lc app=leetcode id=347 lang=cpp
 * @lcpr version=30400
 *
 * [347] Top K Frequent Elements
 */
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 用哈希表计数
        // 来一个二叉堆 nlogn
        unordered_map<int, int> mp;
        for (auto &num : nums)
        {
            mp[num]++;
        }
        struct cmp
        {
            bool operator()(pair<int, int> a, pair<int, int> b)
            {
                return a.second < b.second; // 小于就是大根堆
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto &pair : mp)
        {
            pq.push(pair);
        }
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,3,1,3,2]\n2\n
// @lcpr case=end

 */
