/*
 * @lc app=leetcode id=232 lang=cpp
 * @lcpr version=30307
 *
 * [232] Implement Queue using Stacks
 */
#include "lc.h"
// @lc code=start
class MyQueue {
    stack<int> s1,s2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s2.push(x);
    }
    void move(){
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop() {
        if (s1.empty()){
            move();
        }
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
               if (s1.empty()){
            move();
        }
        return s1.top();
    }
    
    bool empty() {
        if (s1.empty()&&s2.empty())
        return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]\n
// @lcpr case=end

 */

