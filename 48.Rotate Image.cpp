/*
 * @lc app=leetcode id=48 lang=cpp
 * @lcpr version=30401
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto m = matrix.size();
        auto n = matrix[0].size();
        // 先对角线翻转
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // 再每行翻转
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n/2; j++)
            {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
        
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */

