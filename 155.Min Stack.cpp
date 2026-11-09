/*
 * @lc app=leetcode id=155 lang=cpp
 * @lcpr version=30400
 *
 * [155] Min Stack
 */

// @lc code=start

class MinStack
{
    // 这是我自己想的方法
    // 实际上可以不用 minVal

  public:
    stack<int> st;
    stack<int> aux_min;

    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        if (aux_min.empty() || val < aux_min.top())
            aux_min.push(val);
        else
        {
            aux_min.push(aux_min.top());
        }
    }

    void pop()
    {
        st.pop();
        aux_min.pop();
    }
    int top()
    {
        return st.top();
    }
    int getMin()
    {
        return aux_min.top();
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
