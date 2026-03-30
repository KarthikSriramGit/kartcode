class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> groups;
    FreqStack() {
        
    }
    int maxcount = 0;
    void push(int val) {
        freq[val]++;
        maxcount = max(maxcount, freq[val]);
        groups[freq[val]].push(val);
    }
    int pop() {
        int val = groups[maxcount].top();
        groups[maxcount].pop();
        freq[val]--;
        if(groups[maxcount].empty()) maxcount--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */