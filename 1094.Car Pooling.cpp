/*
 * @lc app=leetcode id=1094 lang=cpp
 * @lcpr version=30307
 *
 * [1094] Car Pooling
 */
#include "lc.h"
// @lc code=start
class Solution {
    class DiffVec{
        public:
        vector<int> diff;
        DiffVec(const vector<int>& ori){
            diff.resize(ori.size());
            diff[0]=ori[0];
            for(int i=1;i<ori.size();i++){
                diff[i] = ori[i]-ori[i-1];
            }
        };
        vector<int> restore(){
            vector<int> ret(diff.size(),0);
            ret[0]=diff[0];
            for(int i = 1;i<diff.size();i++){
                ret[i] = ret[i-1]+diff[i];
            }
            return ret;
        };
        void 加减(int i,int j, int val){
            diff[i]+=val;
            if (j+1<diff.size())diff[j+1]-=val;//boundary condition
        };

    };
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        DiffVec d(vector<int>(1001,0));
        for(const auto& t: trips){
            d.加减(t[1],t[2]-1,t[0]);
        }
        auto temp = d.restore();
        return *max_element(temp.begin(),temp.end())>capacity?false:true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,5],[3,3,7]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,5],[3,3,7]]\n5\n
// @lcpr case=end

 */

