/*
 * @lc app=leetcode id=215 lang=cpp
 * @lcpr version=30400
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
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
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(0));

        // 两路划分还是会 TLE
        auto partition = [&](int left, int right) {
            // randomly choose pivot
            auto randomIndx = left + rand() % (right - left + 1);
            swap(nums[left], nums[randomIndx]);
            auto pivot = nums[left];
            auto j = left;
            for (int i = left + 1; i <= right; i++)
            {
                if (nums[i] < pivot)
                {
                    j++;
                    swap(nums[i], nums[j]);
                }
            }
            swap(nums[left], nums[j]);
            return j;
        };

        auto partition3 = [&](int l, int r) -> pair<int, int> {
            // 随机挑一个当 pivot
            auto randomIndx = l + rand() % (r - l + 1);
            swap(nums[l], nums[randomIndx]);

            int pivot = nums[l];
            int lt = l;    // l+1 lt 小于 pivot
            int gt = r;    // gt  r 大于 pivot
            int i = l + 1; // lt+1  i-1 等于 pivot

            while (i <= gt) //
            {
                if (nums[i] < pivot) // 遇到小的
                {
                    // 当前的小于区就是从 lt开始，所以放到 lt+1
                    swap(nums[i], nums[lt + 1]);
                    lt++; // 小于的区间就增加
                    i++;  // 继续扫描
                }
                else if (nums[i] > pivot)
                {
                    // 当前的大于区 r，包括 r，所以直接扔到 r
                    swap(nums[i], nums[gt]);
                    // 无需 i++ ，因为扔过来的数字是未知的
                    gt--;
                }
                else
                {
                    i++;
                }
            }
            swap(nums[l], nums[lt]); // 放回正确的地方
            return {lt, gt};
        };

        int left = 0;
        int right = nums.size() - 1;
        int res;
        while (1)
        {
            // 随机确定一个元素的位置
            auto [lt, gt] = partition3(left, right);
            // 如果在要找的位置后面，再找前面就行了
            if (nums.size() - k < lt)
            {
                right = lt - 1;
            }
            else if (nums.size() - k > gt)
            {
                left = gt + 1;
            }
            else
            {
                res = nums[lt];
                break;
            }
        }
        return res;
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
