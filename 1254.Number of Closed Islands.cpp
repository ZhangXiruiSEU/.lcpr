/*
 * @lc app=leetcode id=1254 lang=cpp
 * @lcpr version=30400
 *
 * [1254] Number of Closed Islands
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {

        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        function<bool(int ,int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n)
            {
                // 超出索引边界
                return false;
            }
            if (grid[i][j]==1){
                return true;
            }
            grid[i][j]=1;
            bool res=1;
            res*=dfs(i+1,j);
            res*=dfs(i,j+1);
            res*=dfs(i-1,j);
            res*=dfs(i,j-1);
            return res;
        };
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j]==0){
                    
                    if(dfs(i,j)) res++;
                    
                }
            }
        }
        return res;
    
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1,1,1],[1,0,0,0,0,0,1],[1,0,1,1,1,0,1],[1,0,1,0,1,0,1],[1,0,1,1,1,0,1],[1,0,0,0,0,0,1],[1,1,1,1,1,1,1]]\n
// @lcpr case=end

 */

