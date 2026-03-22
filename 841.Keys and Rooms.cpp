/*
 * @lc app=leetcode id=841 lang=cpp
 * @lcpr version=30400
 *
 * [841] Keys and Rooms
 */

// @lc code=start
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
class Solution
{
  public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        // 相当于去收集钥匙吧
        // 不就相当于图吗，看看是不是能走到所有节点？
        // dfs bfs 看心情了
        
        std::vector<int> visited(rooms.size(), 0);

        // -----dfs------------
        // auto dfs = [&](auto &&self, int start = 0)->void {
        //     visited[start] = 1;
        //     for (auto key : rooms[start])
        //     {
        //         if (visited[key] == 0)
        //             self(self, key);
        //     }
        // };
        // dfs(dfs);
        


        // ------- bfs ------
        // std::queue<int> q;
        // q.push(0);
        
        // while (!q.empty())
        // {
        //     auto cur = q.front();
        //     q.pop();
        //     visited[cur] = 1;
        //     for (auto key : rooms[cur])
        //     {
        //         if (visited[key] == 0)
        //             q.push(key);
        //     }
        // }


        // ------- dfs 非递归写法，其实就是把 queue 换成 stack------
        std::stack<int> q;
        q.push(0);
        
        while (!q.empty())
        {
            auto cur = q.top();
            q.pop();
            visited[cur] = 1;
            for (auto key : rooms[cur])
            {
                if (visited[key] == 0)
                    q.push(key);
            }
        }
         auto it =  std::find(visited.begin(), visited.end(), 0);
         return it!=visited.end()?false:true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1],[2],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[3,0,1],[2],[0]]\n
// @lcpr case=end

 */
