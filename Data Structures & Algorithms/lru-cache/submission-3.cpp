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
    int capacity;
    unordered_map<int, ListNode*> cache;
    ListNode* left;
    ListNode* right;
    void remove(ListNode* node){
        ListNode* prv = node->prev;
        ListNode* nxt  = node->next;
        prv->next = nxt;
        nxt->prev = prv;

    }
    void insert(ListNode* node){
        ListNode* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
    LRUCache(int capacity) {
        cache.clear();
        left = new ListNode(0,0);
        right = new ListNode(0,0);
        this->capacity = capacity;
        right->prev = left;
        left->next = right;
    }

    int get(int key) {
        if(cache.find(key)!=cache.end()){
            ListNode* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }    
        return -1;
    }   
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            ListNode* curr = cache[key];
            remove(cache[key]);
        }
        ListNode* newNode = new ListNode(key, value);
        cache[key] = newNode;
        insert(newNode);
        if(cache.size() > capacity){
            ListNode* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
