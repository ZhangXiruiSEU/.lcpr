/*
 * @lc app=leetcode id=207 lang=cpp
 * @lcpr version=30307
 *
 * [207] Course Schedule
 */
#include "lc.h"
// @lc code=start
class Solution {
    vector<vector<int>> graph;
    vector<bool> onPath;
    vector<bool> visited;
    bool can{true};
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
        onPath.assign(numCourses,false);
        visited.assign(numCourses,false);
        graph.assign(numCourses,vector<int>(0));
        for (const auto & p:prerequisites ){
            graph[p[0]].push_back(p[1]);
        }
        for( int i=0;i<graph.size();i++){
            dfs(graph,i);
        }
        return can;
    }
    void dfs(vector<vector<int>>& prerequisites, int s){
        if (!can) return;
          if (onPath[s]) {
            // s 已经在递归路径上，说明成环了
            can = false;
            return;
        }
        if(visited[s]) return;
           visited[s] = true;
        onPath[s] = true;
        for (int t : graph[s]) {
            dfs(graph, t);
        }
        onPath[s] = false;
    }

};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

