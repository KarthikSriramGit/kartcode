struct Node {
    int key, val, freq;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
};

class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, Node*> cache;  // key -> node
    // For each frequency, a doubly linked list: head (dummy) <-> ... <-> tail (dummy). LRU at head->next, MRU at tail->prev.
    unordered_map<int, pair<Node*, Node*>> freqLists;  // freq -> (head_dummy, tail_dummy)

    void insertAtFreq(int freq, Node* node) {
        if (freqLists.find(freq) == freqLists.end()) {
            Node* h = new Node(-1, -1);
            Node* t = new Node(-1, -1);
            h->next = t;
            t->prev = h;
            freqLists[freq] = {h, t};
        }
        Node* tail = freqLists[freq].second;
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }

    void removeFromFreq(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void maybeCleanEmptyFreq(int freq) {
        if (freqLists.find(freq) == freqLists.end()) return;
        Node* head = freqLists[freq].first;
        Node* tail = freqLists[freq].second;
        if (head->next != tail) return;
        delete head;
        delete tail;
        freqLists.erase(freq);
    }

    public:
    LFUCache(int cap) : capacity(cap), minFreq(0) {}

    int get(int key) {
        if (capacity == 0 || cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        int oldFreq = node->freq;
        removeFromFreq(node);
        maybeCleanEmptyFreq(oldFreq);
        if (minFreq == oldFreq && freqLists.find(oldFreq) == freqLists.end())
            minFreq = oldFreq + 1;
        node->freq++;
        insertAtFreq(node->freq, node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        if (cache.find(key) != cache.end()) {
            cache[key]->val = value;
            get(key);
            return;
        }
        if (cache.size() == capacity) {
            Node* head = freqLists[minFreq].first;
            Node* tail = freqLists[minFreq].second;
            Node* lru = head->next;
            removeFromFreq(lru);
            cache.erase(lru->key);
            delete lru;
            maybeCleanEmptyFreq(minFreq);
        }
        Node* node = new Node(key, value);
        insertAtFreq(1, node);
        cache[key] = node;
        minFreq = 1;
    }
};