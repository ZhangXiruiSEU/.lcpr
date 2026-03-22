/*
 * @lc app=leetcode id=134 lang=cpp
 * @lcpr version=30400
 *
 * [134] Gas Station
 */

// @lc code=start
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, vector<int>& cost) {
        //vector<int> net_cost (gas.size());
        int sum = 0;
        int min_indx = -1;
        int sum_min = INT_MAX;
        for (int i =0;i<gas.size();i++){
            //net_cost[i]
            //int sum_last = sum;

            sum  =sum + gas[i] - cost[i];
            // 必须记录全局最小值，而不能只是比较相邻的
            if (sum<sum_min) {
                sum_min = sum;
                min_indx = (i+1)%gas.size();
            }
        }
        return sum>=0?min_indx:-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n[3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end

 */

