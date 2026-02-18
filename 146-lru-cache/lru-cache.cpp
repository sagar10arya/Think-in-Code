class Node{
public:
    int key;
    int value;
    Node* prev = NULL;
    Node* next = NULL;

    Node(int k, int v)
    {
        key = k;
        value = v;
    }
};

class LRUCache {
    // Time Complexity: O(1)
    // Space Complexity: O(capacity)
private:
    unordered_map<int, Node*> mpp;  // O(1) key lookup
    Node* head;         // Dummy head (Most Recently Used side)
    Node* tail;         // Dummy tail (Least Recently Used side)
    int capacity;

    // remove a node from DLL
    void deleteNode(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert node right after head (Most Recently Used position)
    void insertAfterHead(Node* node)
    {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }
public:
    // contructor: time and space: O(1)
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    // O(1)
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);  // move accessed node to front (MRU)
        return node->value;
    }
    
    // O(1)
    void put(int key, int value) {
        // key exits
        if(mpp.find(key) != mpp.end())
        {
            Node* node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            // if cache is full: remove LRU
            if(mpp.size() == capacity)
            {
                Node* lru = tail->prev;
                deleteNode(lru);
                mpp.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */