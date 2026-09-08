class MinStack {
public:

    std::stack<int> stack;
    std::stack<int> minStack;

    MinStack() {

    }
    
    void push(int val) {
        stack.push(val);
        // if minstack is empty, val = val, if its not, val = minstack top elem
        val = std::min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
