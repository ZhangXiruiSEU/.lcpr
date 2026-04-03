/*
 * @lc app=leetcode id=743 lang=cpp
 * @lcpr version=30400
 *
 * [743] Network Delay Time
 */

// @lc code=start
class Solution
{
  public:
    struct State
    {
        // 当前节点 ID
        int node;
        // 从起点 s 到当前 node 节点的最小路径权重和
        int distFromStart;

        State(int node, int distFromStart) : node(node), distFromStart(distFromStart)
        {
        }

        bool operator<(const State &other) const
        {
            return distFromStart > other.distFromStart;
        }
    };

    // Dijkstra 算法模板 https://labuladong.online/algo/data-structure/dijkstra/
    vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int src)
    {
        int n = graph.size();
        // 记录从开头到所有节点的距离  why？
        vector<int> distTo(n, INT_MAX);
        // 起点 
        distTo[src] = 0;


        priority_queue<State> pq;
        pq.push(State(src, 0));
        
        while (!pq.empty())
        {
            // 当前节点出队
            State state = pq.top();
            pq.pop();


            int curNode = state.node;
            int curDistFromStart = state.distFromStart;
            // 如果之前记录的数据比现在的小，那就不必再计算了
            if (distTo[curNode] < curDistFromStart)
            {
                continue;
            }
            // 访问领居
            for (auto &neighbor : graph[curNode])
            {
                int nextNode = neighbor.first;
                int nextDistFromStart = curDistFromStart + neighbor.second;
                // 如果之前记录的数据比现在的小，那就不必再计算了
                if (distTo[nextNode] <= nextDistFromStart)
                {
                    continue;
                }
                pq.push(State(nextNode, nextDistFromStart));
                distTo[nextNode] = nextDistFromStart;
            }
        }

        return distTo;
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // 节点编号是从 1 开始的，所以要一个大小为 n + 1 的邻接表
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 1; i <= n; i++)
        {
            graph[i] = vector<pair<int, int>>();
        }
        // 构造图
        for (auto &edge : times)
        {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            // from -> List<(to, weight)>
            // 邻接表存储图结构，同时存储权重信息
            graph[from].push_back({to, weight});
        }

        vector<int> distTo = dijkstra(graph, k);

        // 找到最长的那条最短路径
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (distTo[i] == INT_MAX)
            {
                // 有节点不可达
                return -1;
            }
            res = max(res, distTo[i]);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,1],[2,3,1],[3,4,1]]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n2\n
// @lcpr case=end

 */
