/*
 * @lc app=leetcode id=785 lang=cpp
 * @lcpr version=30307
 *
 * [785] Is Graph Bipartite?
 */
#include "lc.h"
// @lc code=start
class Solution
{
    vector<bool> visited;
    vector<bool> color;
    bool res{true};

  public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        visited.resize(graph.size(), false);
        color.resize(graph.size(), false);
        for (int v = 0; v < graph.size(); v++)
        {
            bfs(graph, v);
        }
        return res;
    }
    void bfs(vector<vector<int>> &graph, int start)
    {
        if (visited[start]==true||res==false) return;
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {

            auto cur = q.front();
            q.pop();
            for (auto &neighbor : graph[cur])
            {
                if (visited[neighbor])
                {
                    if (color[neighbor] == color[cur])
                    {
                        res = false;
                        return;
                    }
                }
                else
                {
                    visited[neighbor] = true;
                    color[neighbor] = !color[cur];
                    q.push(neighbor);
                }
            }
        }
    }
    /*
        bool isBipartite(vector<vector<int>>& graph) {
            visited.resize(graph.size(),false);
            color.resize(graph.size(),false);
            for (int v = 0;v<graph.size();v++){
                traverseRecursively(graph,v);
            }
            return res;
        }
        void traverseRecursively(const vector<vector<int>>& graph,int node){
            if (visited[node]||!res) return;
            visited[node] = true;
            for (const auto & neighbor : graph[node]){
                if (visited[neighbor]) {
                    if (color[neighbor] == color[node]){
                        res = false;
                        return;
                    }
                }
                else {
                    color[neighbor] = !color[node];
                    traverseRecursively(graph,neighbor);
                }

            }
        }
    */
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[0,2],[0,1,3],[0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[0,2],[1,3],[0,2]]\n
// @lcpr case=end

 */
