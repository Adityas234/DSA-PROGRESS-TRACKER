class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    // Key ko DLL ke Node pointer se map karne ke liye
    unordered_map<int, Node*> cacheMap; 
    
    // Dummy Head aur Tail nodes taaki edge cases handle karna aasan ho
    Node* head;
    Node* tail;

    // Node ko Head ke just baad (Most Recently Used position) add karne ke liye helper function
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Node ko uski current position se remove karne ke liye helper function
    void removeNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Jab bhi koi key access ya update ho, usse Head par shift karne ke liye
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }
        Node* resNode = cacheMap[key];
        moveToHead(resNode);
        return resNode->value;
    }
    
    void put(int key, int value) {
        // Case 1: Agar key pehle se exist karti hai, toh value update karo aur Head par move karo
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* existingNode = cacheMap[key];
            existingNode->value = value;
            moveToHead(existingNode);
        } 
        // Case 2: Agar key nayi hai
        else {
            // Agar cache full hai, toh LRU (Tail ke pehle wala) node delete karo
            if (cacheMap.size() == capacity) {
                Node* lruNode = tail->prev;
                cacheMap.erase(lruNode->key); // Map se hatao
                removeNode(lruNode);          // DLL se hatao
                delete lruNode;               // Memory free karo
            }
            
            // Naya node banao, Head par add karo aur Map mein daalo
            Node* newNode = new Node(key, value);
            cacheMap[key] = newNode;
            addNode(newNode);
        }
    }
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */