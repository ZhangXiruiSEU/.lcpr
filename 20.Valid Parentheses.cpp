/*
 * @lc app=leetcode id=20 lang=cpp
 * @lcpr version=30400
 *
 * [20] Valid Parentheses
 */
#include "lc.h"
#include <stack>
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('&');//Sentinel , occupy the position
        //if (s.size()%2!=0) return false;
        
        for (auto& ch :s){
            if (ch =='('||ch =='['||ch =='{'){
                st.push(ch);
            }
            else if (ch ==')'){
                if (st.top()!='(')
                    return false;
                else st.pop();
            }
            else if (ch ==']'){
                if (st.top()!='[')
                    return false;
                else st.pop();
            }
            else if (ch =='}'){
                if (st.top()!='{')
                    return false;
                else st.pop();
            }
        }
        return st.top()=='&';
       
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */

