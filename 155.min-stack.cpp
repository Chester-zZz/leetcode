/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (35.84%)
 * Total Accepted:    273.9K
 * Total Submissions: 763.9K
 * Testcase Example:
 * '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 *
 *
 * pop() -- Removes the element on top of the stack.
 *
 *
 * top() -- Get the top element.
 *
 *
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 *
 * Example:
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 *
 */
#include <limits.h>
#include <stack>
class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() : m_min(INT_MAX) {}

    void push(int x) {
        if (x <= m_min) {
            m_stack.push(m_min);
            m_min = x;
        }
        m_stack.push(x);
    }

    void pop() {
        if (m_stack.empty()) {
            return;
        }
        if (m_stack.top() == m_min) {
            m_stack.pop();
            m_min = m_stack.top();
        }
        m_stack.pop();
    }

    int top() { return m_stack.top(); }

    int getMin() { return m_min; }

   private:
    int m_min;
    std::stack<int> m_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
