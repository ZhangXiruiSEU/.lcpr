/*
 * @lc app=leetcode id=73 lang=cpp
 * @lcpr version=30400
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution
{
  public:
    // 这个不占用额外空间的方法是很绕的，最好还是画个图来理解
    //  最直观的方法就是开俩数组，代表行和列要不要 set zero ，但是不满足题目要求
    void setZeroes(vector<vector<int>> &matrix)
    {
        auto m = matrix.size();
        auto n = matrix[0].size();
        bool row0 = false, col0 = false;
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
            {
                row0 = true;
                break;
            }

        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
            {
                col0 = true;
                break;
            }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row0)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        if (col0)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n
// @lcpr case=end

 */
