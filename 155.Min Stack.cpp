/*
 * @lc app=leetcode id=155 lang=cpp
 * @lcpr version=30400
 *
 * [155] Min Stack
 */

// @lc code=start
#include <climits>
#include <iterator>
#include <queue>
class MinStack {
    // 这是我自己想的方法
    // 实际上可以不用 minVal 变量更简洁
    
public:
    stack<int> st;
    stack<int> aux;
    int minVal=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        minVal = min(minVal,val);
        st.push(val);
        aux.push(minVal);
    }
    
    void pop() {
        st.pop();
        aux.pop();
        //必须维护这个 minVal
        minVal =aux.empty()?INT_MAX:aux.top();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return aux.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */

