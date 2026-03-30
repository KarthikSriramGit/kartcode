class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    int k_val;
    KthLargest(int k, vector<int>& nums) {
        k_val = k;
        for (int n : nums) {
            add(n);
        }
    }
    int add(int val) {
        heap.push(val);
        if(heap.size() > k_val){
            heap.pop();
        }
        return heap.top();
    }
};