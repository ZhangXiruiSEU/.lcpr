/*
 * @lc app=leetcode id=128 lang=cpp
 * @lcpr version=30400
 *
 * [128] Longest Consecutive Sequence
 */
#include "lc.h"
#include <unordered_set>
// @lc code=start
class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        // 哈希存储数组，方便查找是否存在某个值
        unordered_set<int> st(nums.begin(), nums.end());
        int maxRes = 0;
        // 遍历
        for (const int &n : st)
        {
            // 如果说找不到某个值的前一个值，说明这个是可能的开头
            if (st.count(n - 1) != 0)
            {
                continue;
            }

            int tempRes = 1;// 把开头算上
            int tempN = n;//从 n 值开始往后找
            
            //找得到就一直找
            while (st.count(tempN + 1) == 1)
            {
                tempRes++;
                tempN++;
            }
            //更新最大值
            maxRes = max(tempRes, maxRes);
        }
        return maxRes;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,2]\n
// @lcpr case=end

 */
