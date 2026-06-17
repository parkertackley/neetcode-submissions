class MinStack {
public:
    stack<pair<int, int>> stack;

    MinStack() {
        
    }
    
    void push(int val) {
        if (stack.empty())
        {
            stack.push({val, val});
        } else
        {
            pair<int, int> top = stack.top();
            int emin = min(val, top.second);
            stack.push({val, emin});
        }
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
    }
};
