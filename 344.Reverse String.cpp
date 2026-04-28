/*
 * @lc app=leetcode id=344 lang=cpp
 * @lcpr version=30304
 *
 * [344] Reverse String
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution
{
  public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            auto temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */
