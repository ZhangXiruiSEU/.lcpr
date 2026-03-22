/*
 * @lc app=leetcode id=773 lang=cpp
 * @lcpr version=30307
 *
 * [773] Sliding Puzzle
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        auto get_string = [&](const vector<vector<int>> &b) {
            string s = "";
            for (auto &row : b)
                for (int x : row)
                    s += (x + '0');
            return s;
        };
        auto move = [&](string s ){
            size_t pos = s.find('0');
            
        };
        string start = get_string(board);
        string target = "123450";

        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        int step = 0;
        while (!q.empty())
        {
            int cur_layer_size = q.size();
            for (int i = 0; i < cur_layer_size; i++)
            {
                auto cur_state = q.front();
                q.pop();
                if (cur_state == target)
                {
                    return step;
                }
                for (){
                    q.push()
                }
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,0,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[5,4,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,1,2],[5,0,3]]\n
// @lcpr case=end

 */
