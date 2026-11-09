/*
 * @lc app=leetcode id=215 lang=cpp
 * @lcpr version=30400
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <functional>
#include <queue>
#include <vector>
class Solution
{
  public:
    // 最直观的思路就是堆排序，
    // 大顶堆可以，把元素全压进去，然后弹出第 k 个，但是很糙，
    // 复杂度是 nlogn+k  空间是n 相当于全排序了

    // 小顶堆比较巧 ，维护一个 k 个元素的小顶堆
    // 对顶就是k 个元素最小的一个
    // 如果说满了，如果新元素比堆顶大， 那就把顶踢走，
    // 最终小顶堆就是最大的k 个，堆顶就是其中最小的，就是要求的
    // nlogk  k

    // 但是最优化的方法是快速排序的变式
    // 快排就是先随机找一个元素确定他的正确位置
    //  那这个元素如果比目标大，或者小，都需要继续找一侧就行了
    // 但这个区间问题还是要好好搞清楚
    int findKthLargest_(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, std::greater<int>> pq; // 小顶堆
        for (int n : nums)
        {
            pq.push(n);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }

    int findKthLargest(vector<int> &nums, int k)
    {

        // 两路划分还是会 TLE

        auto partition3 = [&](int l, int r) -> pair<int, int> {
            // 随机挑一个当 pivot
            auto randomIndx = l + rand() % (r - l + 1);
            int pivot = nums[randomIndx];
            int lt = l - 1;
            int gt = r + 1;
            int i = l;

            while (i < gt)
            {
                if (nums[i] < pivot) // 遇到小的
                {
                    lt++; // 小于的区间就增加
                    swap(nums[i], nums[lt]);
                    i++; // 继续扫描
                }
                else if (nums[i] > pivot)
                {
                    gt--;
                    swap(nums[i], nums[gt]);
                    // 无需 i++ ，因为扔过来的数字是未知的
                }
                else
                {
                    i++;
                }
            }
            return {lt, gt};
        };

        int left = 0;
        int right = nums.size() - 1;

        while (1)
        {
            auto [lt, gt] = partition3(left, right);
            if (lt+1 > int(nums.size()) - k)
            {
                right = lt;
            }
            else if (gt-1 < int(nums.size()) - k)
            {
                left = gt ;
            }
            else
            {
                return nums[lt+1];
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,1,5,6,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,1,2,4,5,5,6]\n4\n
// @lcpr case=end

 */
