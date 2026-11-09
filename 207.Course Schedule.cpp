/*
 * @lc app=leetcode id=207 lang=cpp
 * @lcpr version=30307
 *
 * [207] Course Schedule
 */
#include "lc.h"
#include <queue>
#include <vector>
// @lc code=start
class Solution
{
  public:
    bool canFinish_(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> status(numCourses, 0);
        bool flag = true;
        for (const auto &p : prerequisites)
        {
            graph[p[0]].push_back(p[1]);
        }
        auto dfs = [&](auto &&self, int start) -> void {
            if (status[start] == 2)
                return;
            if (status[start] == 1)
            {
                flag = false;
                return;
            }
            if (flag == false)
                return;
            status[start] = 1;
            for (auto &node : graph[start])
            {
                self(self, node);
            }
            status[start] = 2;
        };
        for (int i = 0; i < numCourses; i++)
        {
            dfs(dfs, i);
        }
        return flag;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);
        // vector<int> status(numCourses, 0);
        // bool flag = true;
        for (const auto &p : prerequisites)
        {
            graph[p[0]].push_back(p[1]); // node p[0] get a successor p[1]
            inDegree[p[1]]++;            // so p[1] get a inDegree
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (q.size() != 0)
        {
            auto current = q.front();
            q.pop();
            for (auto succ : graph[current])
            {

                inDegree[succ]--;
                if (inDegree[succ] == 0)
                {
                    q.push(succ);
                }
            }
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] != 0)
            {
                return false;
            }
        }
        return true;
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
