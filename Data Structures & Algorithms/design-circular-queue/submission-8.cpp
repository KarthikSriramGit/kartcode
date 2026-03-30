class MyCircularQueue {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int v) : val(v), next(nullptr), prev(nullptr) {}
    };
    int capacity;
    int size;
    ListNode* left;
    ListNode* right;
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        left = new ListNode(0);
        right = new ListNode(0);
        left->next = right;
        right->prev = left;
    }
    bool enQueue(int value) { // left<->right
        if(isFull()){
            return false;
        }
        ListNode* curr = new ListNode(value); // curr
        curr->next = right; // left <-> right, curr->right
        curr->prev = right->prev; // left <-> right, (left)(<-)curr->right
        right->prev->next = curr; // left <- right, (left)<-(>)curr->right
        right->prev = curr; // (left) /-/ right (disconnected), left<->curr(<)->(right)
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        // left <-> curr <-> right
        ListNode* curr = left->next;
        left->next = left->next->next; // left -> right, (left) <-(broken) curr <->right
        left->next->prev = left; // left (<)-> right, (left)<-curr/-/right
        delete curr;
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
        return isEmpty()? -1 : right->prev->val;
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