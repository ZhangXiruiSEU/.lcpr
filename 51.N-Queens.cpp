/*
 * @lc app=leetcode id=51 lang=cpp
 * @lcpr version=30400
 *
 * [51] N-Queens
 */
#include "lc.h"
#include <functional>
// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n,string(n,'.'));
        //vector<bool> rows(n,false);
        vector<bool> existCols(n,false);
        
        auto isValid = [&](int r, int c){
            if (existCols[c]) return false;
            for (int i = r-1, j = c-1; i>=0 && j>=0 ;i--,j--){
                if (board[i][j] == 'Q') return false;
            }
            for (int i = r-1, j = c+1; i>=0 && j<n ;i--,j++){
                if (board[i][j] == 'Q') return false;
            }

            return true;
        };

        function<void(int)> recur = [&](int rowIndx){
            if (rowIndx == n) {
                result.push_back(board);
                return;
            }
            for (int j = 0;j<n;j++){
                if(isValid(rowIndx,j)){
                    board[rowIndx][j] = 'Q';
                    existCols[j] = true;
                    recur(rowIndx+1);
                    board[rowIndx][j] = '.';
                    existCols[j] = false;
                }
                
            }
        };
        recur(0);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

