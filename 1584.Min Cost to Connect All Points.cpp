/*
 * @lc app=leetcode id=1584 lang=cpp
 * @lcpr version=30400
 *
 * [1584] Min Cost to Connect All Points
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution
{
  public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        
        vector<vector<int>> edges;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back(vector<int>{i,j,dist});
                
            }
        }
        sort(edges.begin(), edges.end(), 
        [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        }
        );
        int cost=0;
        UF uf(points.size());
        for (auto & edge :edges){
            int v1 = edge[0];
            int v2 = edge[1];
            int dist = edge[2];
            if (uf.connected(v1, v2)){
                continue;
            }
            cost += dist;
            uf.unionNodes(v1, v2);

        }
        return cost;

        
    }



    class UF
    {
      public:
        // 连通分量个数
        int count;
        // 存储一棵树
        vector<int> parent;
        // 记录树的「重量」
        vector<int> size;

        // n 为图中节点的个数
        UF(int n) : count(n), parent(n), size(n, 1)
        {
            for (int i = 0; i < n; ++i)
            {
                parent[i] = i;
            }
        }

        // 将节点 p 和节点 q 连通
        void unionNodes(int p, int q)
        {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ)
                return;

            // 小树接到大树下面，较平衡
            if (size[rootP] > size[rootQ])
            {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            }
            else
            {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
            // 两个连通分量合并成一个连通分量
            count--;
        }

        // 判断节点 p 和节点 q 是否连通
        bool connected(int p, int q)
        {
            return find(p) == find(q);
        }

        // 返回节点 x 的连通分量根节点
        int find(int x)
        {
            while (parent[x] != x)
            {
                // 进行路径压缩
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        // 返回图中的连通分量个数
        int getCount()
        {
            return count;
        }
    };
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0],[2,2],[3,10],[5,2],[7,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,12],[-2,5],[-4,1]]\n
// @lcpr case=end

 */
