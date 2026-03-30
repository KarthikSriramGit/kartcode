class MinStack {
public:
    stack<int> stck;
    stack<int> minstck;
    MinStack() {
        
    }
    
    void push(int val) {
        stck.push(val);
        val = min(val, minstck.empty()? val : minstck.top());
        minstck.push(val);
    }
    
    void pop() {
        stck.pop();
        minstck.pop();
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return minstck.top();
    }
};
;