/*
 * @lc app=leetcode id=912 lang=cpp
 * @lcpr version=30400
 *
 * [912] Sort an Array
 */

// @lc code=start
#include <cstdlib>
#include <ctime>
#include <utility>
class Solution
{
  public:
    vector<int> sortArray(vector<int> &nums)
    {
        auto heapify = [&](auto &self, int n, int i) -> void {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n && nums[l] > nums[largest])
                largest = l;
            if (r < n && nums[r] > nums[largest])
                largest = r;

            if (largest != i)
            {
                swap(nums[i], nums[largest]);
                self(self, n, largest);
            }
        };

        int n = nums.size();

        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(heapify, n, i);
        }

        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);
            heapify(heapify, i, 0);
        }

        return nums;
    }

    // 三指针才能突破重复元素很多的情况
    // 但是要特别注意区间边界的问题

    // 暂时性实现了一个比较糙的快排
    vector<int> sortArray_quick(vector<int> &nums)
    {
        srand(time(0));
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
            // nums[left .. lt-1] < pivot
            // nums[lt .. gt] == pivot
            // nums[gt+1 .. right] > pivot

            // 随机挑一个当 pivot
            auto randomIndx = l + rand() % (r - l + 1);
            swap(nums[l], nums[randomIndx]);

            int pivot = nums[l];

            // nums[left+1 .. lt] < pivot
            // nums[lt+1 .. i-1] == pivot
            // nums[i .. gt] unknown
            // nums[gt+1 .. right] > pivot
            int lt = l;
            int gt = r;
            int i = l + 1;

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

        auto qsort = [&](auto &self, int left, int right) -> void {
            if (left >= right)
                return;
            // int p = partition(left, right);
            // self(self, left, p - 1);
            // self(self, p + 1, right);

            // 三路的  重复元素多的情况下就快
            auto [lt, gt] = partition3(left, right);
            self(self, left, lt - 1);
            self(self, gt + 1, right);
        };
        qsort(qsort, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,2,0,0]\n
// @lcpr case=end

 */
