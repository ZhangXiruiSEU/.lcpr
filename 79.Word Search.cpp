/*
 * @lc app=leetcode id=79 lang=cpp
 * @lcpr version=30400
 *
 * [79] Word Search
 */
#include "lc.h"
#include <climits>
#include <vector>
// @lc code=start
class Solution
{
  public:
    bool exist_(vector<vector<char>> &board, string word)
    {
        // dfs
        auto m = board.size();
        auto n = board[0].size();
        bool find = false;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        auto dfs = [&](auto &&self, int x, int y, int indx_w) -> void {
            // end condition

            if (indx_w == word.size())
            {
                find = true;
            }
            for (auto &dir : dirs)
            {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                if (new_x < 0 || new_y < 0 || new_x >= m || new_y >= n)
                    continue;
                if (board[new_x][new_y] == word[indx_w])
                {
                    board[new_x][new_y] ^= 0x80; //
                    self(self, new_x, new_y, indx_w + 1);
                    board[new_x][new_y] ^= 0x80;
                }
            }
        };
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    board[i][j] ^= 0b10000000;
                    dfs(dfs, i, j, 1);
                    board[i][j] ^= 0b10000000;
                }
            }
        }
        return find;
    }
    bool exist(vector<vector<char>> &board, string word)
    {

        auto m = board.size();
        auto n = board[0].size();
        if (word.size() > m * n)
            return false;
        auto visited = board;
        auto find = false;
        auto dfs = [&](auto &&self, int x, int y, int indx) -> void {
            if (find)
                return;
            if (indx == word.size())
            {
                find = true;
                return;
            }
            // 从第一个开始找
            vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for (auto &dir : dirs)
            {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                if (new_x < 0 || new_y < 0 || new_x >= m || new_y >= n)
                    continue;
                if (board[new_x][new_y] == word[indx] && visited[new_x][new_y] != CHAR_MAX)
                {
                    visited[new_x][new_y] = CHAR_MAX;
                    self(self, new_x, new_y, indx + 1);
                    visited[new_x][new_y] = 0;
                }
            }
        };
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] && visited[i][j] != CHAR_MAX && !find)
                {
                    visited[i][j] = CHAR_MAX;
                    dfs(dfs, i, j, 1);
                    visited[i][j] = 0;
                }
            }
        }
        return find;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */
