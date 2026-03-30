class LRUCache {
public:
    struct ListNode{
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int key, int val){
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    unordered_map<int, ListNode*> cache;
    ListNode* left;
    ListNode* right;
    int cap;
    LRUCache(int capacity) {
        cache.clear();
        cap = capacity;
        left = new ListNode(-1, -1);
        right = new ListNode(-1, -1);
        left->next = right;
        right->prev = left;
    }
    void insert(ListNode* node){
        node->next = right;
        node->prev = right->prev;
        right->prev->next = node;
        right->prev = node;
    }
    void remove(ListNode* node){
        ListNode* prv = node->prev;
        prv->next = node->next;
        node->next->prev = prv;
    }

    int get(int key) {
        if(cache.find(key) != cache.end()){
            ListNode* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            ListNode* node = cache[key];
            remove(node);
            delete node;
        }
        ListNode* curr = new ListNode(key,value);
        insert(curr);
        cache[key] = curr;
        if(cache.size() > cap){
            ListNode* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }
    }
};
