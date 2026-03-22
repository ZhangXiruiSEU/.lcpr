/*
 * @lc app=leetcode id=304 lang=cpp
 * @lcpr version=30307
 *
 * [304] Range Sum Query 2D - Immutable
 */
#include "lc.h"
// @lc code=start
class NumMatrix {
    vector<vector<int>> presum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();

        // 一次性初始化好大小，默认值 0
        presum.resize(m + 1, vector<int>(n + 1, 0));

        //make the vector outside the right size.
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                // 二维前缀和公式
                // 注意：matrix 使用 i-1 和 j-1，因为 matrix 是从 0 开始的
                presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        return presum[x2+1][y2+1] - presum[x1][y2+1] - presum[x2+1][y1] + presum[x1][y1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]\n
// @lcpr case=end

 */
