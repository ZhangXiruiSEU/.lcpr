/*
 * @lc app=leetcode id=1109 lang=cpp
 * @lcpr version=30307
 *
 * [1109] Corporate Flight Bookings
 */
#include "lc.h"
// @lc code=start
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
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ori(n,0);
        DiffVec d(ori);
        for (const auto& b:bookings){
            d.加减(b[0]-1,b[1]-1,b[2]);
        }
        return d.restore();

        
    }

};
   
// @lc code=end



/*
// @lcpr case=start
// [[1,2,10],[2,3,20],[2,5,25]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,10],[2,2,15]]\n2\n
// @lcpr case=end

 */

