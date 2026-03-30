class MyCircularQueue {
public:
    struct ListNode{
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int val){
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
    };
    int capacity; 
    int size; 
    ListNode* left;
    ListNode* right;
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        left = new ListNode(-1);
        right = new ListNode(-1);
        left->next = right;
        right->prev = left;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        ListNode* curr = new ListNode(value);
        curr->next = right;
        curr->prev = right->prev;
        right->prev->next = curr;
        right->prev = curr;      
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        ListNode* node = left->next;
        left->next = left->next->next;
        left->next->prev = left;
        delete node;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return left->next->val;
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return right->prev->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */