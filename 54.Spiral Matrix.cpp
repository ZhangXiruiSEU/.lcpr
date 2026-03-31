/*
 * @lc app=leetcode id=54 lang=cpp
 * @lcpr version=30401
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <vector>
class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m= matrix.size(),n=matrix[0].size();
        int up=0,down=m,left=0,right=n;// down 和 right 取不到哦
        vector<int> res;
        while (res.size()<m*n){
            if (left==right)break;
            for (int j = left ;j<right;j++){
                res.push_back(matrix[up][j]);
            }
            up++;

            if (up==down)break;
            for (int i = up ;i<down;i++){
                res.push_back(matrix[i][right-1]);
            }
            right--;
            if (left==right)break;
            for (int j = right-1 ;j>=left;j--){
                res.push_back(matrix[down-1][j]);
            }
            down--;

            if (up==down)break;
            for (int i = down-1 ;i>=up;i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */
