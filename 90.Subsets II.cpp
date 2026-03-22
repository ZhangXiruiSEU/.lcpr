/*
 * @lc app=leetcode id=90 lang=cpp
 * @lcpr version=30400
 *
 * [90] Subsets II
 */
#include "lc.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                vector<int> temp;
        vector<vector<int>> res;
        int count = 0;
    
        auto backtrack = [&](auto&& self,int indx){
            if (indx>=nums.size()){
                res.push_back(temp);
                return;
            }
            temp.push_back(nums[indx]);
            self(self,indx+1);
            temp.pop_back();


            self(self,indx+1);
            

            
        };
        backtrack(backtrack,0 );
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

