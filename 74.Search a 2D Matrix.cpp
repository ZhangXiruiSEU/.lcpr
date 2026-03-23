/*
 * @lc app=leetcode id=74 lang=cpp
 * @lcpr version=30401
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <utility>
class Solution
{
  public:
    // 就是要映射一下 index，想象在搜索一个一维数组
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        auto get2Dval = [&](int i) -> int {
            int row = i / matrix[0].size();
            int col = i % matrix[0].size();

            return matrix[row][col];
        };

        int left = 0;
        int right = matrix.size() * matrix[0].size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int val = get2Dval(mid);
            if (val == target)
            {
                return true;
            }
            else if (val < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end

 */
