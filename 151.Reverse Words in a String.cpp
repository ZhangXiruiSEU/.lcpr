/*
 * @lc app=leetcode id=151 lang=cpp
 * @lcpr version=30400
 *
 * [151] Reverse Words in a String
 */
#include "lc.h"
#include <algorithm>
#include <string>
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        vector<string> res;
        while (i<s.size()){
            while (i<s.size()&&s[i]==' '){
                i++;
            }
            if (i >= s.size()) break;
            int begin = i;
            while (i<s.size()&&s[i]!=' '){
                i++;
            }
            int length = i-begin;
            res.push_back(s.substr(begin,length));
        }
        
        reverse(res.begin(), res.end());
        string sres;
        for (auto & str:res){
            sres+=str;
            sres+=' ';
        }
        sres.resize(sres.size()-1);
        return sres;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */

