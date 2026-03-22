/*
 * @lc app=leetcode id=797 lang=cpp
 * @lcpr version=30307
 *
 * [797] All Paths From Source to Target
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        tra(graph, 0);
        return res;
    }
    void tra(vector<vector<int>>& graph, int start) {
        graph.size();
        path.push_back(start);
        if (start ==graph.size()-1){
            res.push_back(path);
            path.pop_back();
            return;
        }
        for (const auto& v:graph[start]){
            tra(graph, v);
        }
        path.pop_back();
    }

};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,1],[3,2,4],[3],[4],[]]\n
// @lcpr case=end

 */

