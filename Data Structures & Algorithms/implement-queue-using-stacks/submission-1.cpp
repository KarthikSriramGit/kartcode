class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    void push(int x) {
        s1.push(x);   
    }
    
    int pop() {
        for(int i = s1.size() -1; i > 0; i--){
            s2.push(s1.top()); s1.pop();
        }
        int result = s1.top(); 
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top()); s2.pop();
        }
        return result;
    }
    
    int peek() {
        for(int i = s1.size() -1; i > 0; i--){
            s2.push(s1.top()); s1.pop();
        }
        int result = s1.top(); 
        while(!s2.empty()){
            s1.push(s2.top()); s2.pop();
        }
        return result;
    }
    
    bool empty() {
        return s1.empty();
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