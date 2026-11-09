/*
 * @lc app=leetcode id=239 lang=cpp
 * @lcpr version=30307
 *
 * [239] Sliding Window Maximum
 */
#include "lc.h"
#include <deque>
// @lc code=start
class Solution
{
  public:
    class MonotonicQueue
    {
        deque<int> maxq;

      public:
        // 在尾部添加一个元素 n，维护 maxq 的单调性质
        void push(int n)
        {
            // 将前面小于自己的元素都删除
            while (!maxq.empty() && maxq.back() < n)
            {
                maxq.pop_back();
            }
            maxq.push_back(n);
        }
        int max()
        {
            return maxq.front();
        }

        void pop(int n)
        {
            if (n == maxq.front())
            {
                maxq.pop_front();
            }
        }
    };
    vector<int> maxSlidingWindow_(vector<int> &nums, int k)
    {
        MonotonicQueue window;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < k - 1)
            {
                // 先填满窗口的前 k - 1
                window.push(nums[i]);
            }
            else
            {
                // 窗口向前滑动，加入新数字
                window.push(nums[i]);
                // 记录当前窗口的最大值
                res.push_back(window.max());
                // 移出旧数字
                window.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {

            // 窗口向前滑动，加入新数字
            while (!dq.empty() && dq.back() < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);

            if (i >= k - 1)
            {
                // 记录当前窗口的最大值
                res.push_back(dq.front());
                // 移出旧数字
                if (dq.front() == nums[i - k + 1])
                    dq.pop_front();
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
