/*
 * @lc app=leetcode id=1905 lang=cpp
 * @lcpr version=30400
 *
 * [1905] Count Sub Islands
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid2.size();
        int n = grid2[0].size();
        function<void(int, int, bool &)> dfs = [&](int i, int j,bool& isSub) {
            if (i < 0 || j < 0 || i >= m || j >= n)
            {    // 超出索引边界
                return;
            }
            if (grid2[i][j] == 0)
            {
                return;
            }
            grid2[i][j] = 0;
            if (grid1[i][j]==0) isSub=false;
            dfs(i + 1, j, isSub);
            dfs(i, j + 1, isSub);
            dfs(i - 1, j, isSub);
            dfs(i, j - 1, isSub);
            return ;
        };
        int res=0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid2[i][j] == 1)
                {
                    bool isSub = true;
                    dfs(i,j,isSub);
                    if (isSub) res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
//
[[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]\n[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]\n
// @lcpr case=end

// @lcpr case=start
//
[[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]]\n[[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]\n
// @lcpr case=end

 */
