/*
 * @lc app=leetcode id=225 lang=cpp
 * @lcpr version=30304
 *
 * [225] Implement Stack using Queues
 */
#include "lc.h"
// @lc code=start
class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for(size_t i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
        auto temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]\n
// @lcpr case=end

 */

