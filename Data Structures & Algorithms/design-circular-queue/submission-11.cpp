class MyCircularQueue {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int val){
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    int capacity;
    int count = 0;
    ListNode *left, *right;
    MyCircularQueue(int k){
        capacity = k;
        left = new ListNode(-1);
        right = new ListNode(-1);
        right->prev = left;
        left->next = right;
    }
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        ListNode* node = new ListNode(value);
        node->prev = right->prev;
        node->next = right;
        right->prev->next = node;
        right->prev = node;
        count++;
        return true;   
    }   
    
    bool deQueue() {
        if(isEmpty()) return false;
        ListNode* node = left->next;
        left->next = left->next->next;
        left->next->prev = left;
        delete node;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return left->next->val;
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return right->prev->val;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};