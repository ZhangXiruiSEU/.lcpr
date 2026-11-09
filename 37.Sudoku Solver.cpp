/*
 * @lc app=leetcode id=37 lang=cpp
 * @lcpr version=30400
 *
 * [37] Sudoku Solver
 */
#include "lc.h"
#include <functional>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start

class Solution
{
  public:
    void solveSudoku(vector<vector<char>> &board)
    {
        // its better to convert i j to just one number
        auto getIJ = [](int num) -> vector<int> {
            int i = num / 9;
            int j = num % 9;
            return {i, j};
        };

        // 通过 ij 找到 box id
        auto getBoxIndx = [](int i, int j) { return i / 3 * 3 + j / 3; };

        // 哈希表记录合法性
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> columns(9);
        vector<unordered_set<int>> boxes(9);
        // 先把题干的信息放进去
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                boxes[getBoxIndx(i, j)].insert(board[i][j]);
            }
        }
        // 一个小函数检测某个位置能不能放某个数字
        auto isValid = [&](int i, int j, int num) {
            if (rows[i].count(num))
                return false;
            if (columns[j].count(num))
                return false;
            if (boxes[getBoxIndx(i, j)].count(num))
                return false;
            return true;
        };

        //
        bool find = false;

        // 递归去找  属于回溯法吧
        auto recur = [&](auto &&self, int num) {
            if (num == 81)
            {
                find = true;
                return;
            }
            //
            int i = num / 9;
            int j = num % 9;
            if (board[i][j] != '.')
            {
                self(self, num + 1);
                return;
            }
            // 一个一个试
            for (char n = '1'; n <= '9'; n++)
            {
                if (isValid(i, j, n))
                {
                    board[i][j] = n;
                    rows[i].insert(n);
                    columns[j].insert(n);
                    boxes[getBoxIndx(i, j)].insert(n);
                    self(self, num + 1);
                    if (find)
                        return;
                    board[i][j] = '.';
                    rows[i].erase(n);
                    columns[j].erase(n);
                    boxes[getBoxIndx(i, j)].erase(n);
                }
            }
        };
        recur(recur, 0);
    };
    void solveSudoku_(vector<vector<char>> &board)
    {
        bool found = false;
        auto getBoxIndx = [=](int r, int c) {
            return (r / 3) * 3 + c / 3; // 0 - 8
        };
        vector<vector<bool>> rows(9, vector<bool>(10));
        vector<vector<bool>> cols(9, vector<bool>(10));
        vector<vector<bool>> boxs(9, vector<bool>(10));
        vector<pair<int, int>> spaces;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                if (board[i][j] == '.')
                {
                    spaces.push_back({i, j});
                    continue;
                }
                rows[i][board[i][j] - '0'] = true;
                cols[j][board[i][j] - '0'] = true;
                boxs[getBoxIndx(i, j)][board[i][j] - '0'] = true;
            }
        }
        auto isValid = [&](int c, int r, int val) {
            if (rows[r][val] || cols[c][val] || boxs[getBoxIndx(r, c)][val])
                return false;
            return true;
        };
        function<void(int)> recur = [&](int indx) {
            if (found)
                return;
            if (indx == spaces.size())
            {
                found = true;
                return;
            }

            int r = spaces[indx].first;
            int c = spaces[indx].second;

            for (int n = 1; n <= 9; n++)
            {
                if (!isValid(c, r, n))
                    continue;
                board[r][c] = n + '0';
                rows[r][n] = true;
                cols[c][n] = true;
                boxs[getBoxIndx(r, c)][n] = true;
                recur(indx + 1);
                if (found)
                    return;
                board[r][c] = '.';
                rows[r][n] = false;
                cols[c][n] = false;
                boxs[getBoxIndx(r, c)][n] = false;
            }
        };
        recur(0);
        // return board;
    }
};

// @lc code=end

/*
// @lcpr case=start
//
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */
