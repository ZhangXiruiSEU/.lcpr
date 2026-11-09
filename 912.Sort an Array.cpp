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
#include <vector>
class Solution
{
  public:
    vector<int> sortArray(vector<int> &nums)
    {
        return sortArray_heap(nums);
    }

    vector<int> sortArray_quick3(vector<int> &nums)
    {
        srand(time(0));
        // we used close interval for the sort problem
        auto partition3 = [&](auto &&self, int left, int right) -> void {
            auto len = right - left + 1;
            if (len == 1 || len == 0)
                return;
            auto pivot_indx = rand() % len + left;
            auto pivot = nums[pivot_indx];
            auto p0 = left - 1;
            auto p1 = right + 1;
            auto i = left;
            while (i < p1)
            {
                if (nums[i] < pivot)
                {
                    p0++;
                    swap(nums[i], nums[p0]);
                    i++;
                }
                else if (nums[i] > pivot)
                {
                    p1--;
                    swap(nums[i], nums[p1]);
                }
                else
                {
                    i++;
                }
            }
            self(self, left, p0);
            self(self, p1, right);
        };
        partition3(partition3, 0, nums.size() - 1);
        return nums;
    }
    vector<int> sortArray_merge(vector<int> &nums)
    {
        return nums;
    }
    vector<int> sortArray_heap(vector<int> &nums)
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
