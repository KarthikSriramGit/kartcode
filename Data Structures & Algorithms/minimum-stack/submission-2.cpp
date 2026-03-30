class MinStack {
public:
    stack<int> stck;
    stack<int> min;
    MinStack() {
        
    }
    void push(int val) {
        stck.push(val);
        if(min.empty() || val <= min.top()){
            min.push(val);
        }
    }
    
    void pop() {
        if(min.top() == stck.top()){
            min.pop();
        }
        stck.pop();
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return min.top();
    }
};
