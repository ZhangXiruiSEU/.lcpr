/*
 * @lc app=leetcode id=46 lang=cpp
 * @lcpr version=30307
 *
 * [46] Permutations
 */
#include "lc.h"
#include <functional>
#include <vector>
// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        vector<int> visited(nums.size(),false);
        std::vector<std::vector<int>> res;

        function<void()> recur = [&](){
            if (track.size()==nums.size()){
                res.push_back(track);
                return;
            }
            for (int i = 0; i < nums.size(); i++){
                if (visited[i]) //维护一个 visited 就不用遍历 track 了
                    continue;
                track.push_back(nums[i]);
                visited[i] = true;//成对出现
                recur();
                track.pop_back();
                visited[i] = false;//成对出现
            }
        };
        recur();
        return res;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

