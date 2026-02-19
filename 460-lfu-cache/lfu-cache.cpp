class Node{
public:
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

class List{
public:
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node)
    {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* delNode)
    {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    int maxSizeCache;   // capacity
    int minFreq;        // smallest frequency in cache
    int curSize;        // current number of elements

    // moves node from old frequency list to new frequency list
    void updateFreqListMap(Node* node)
    {
        keyNode.erase(node->key); // Remove node from keyNode map temporarily

        // Remove node from its current frequency list
        freqListMap[node->cnt]->removeNode(node);

        // If this node had the minimum frequency
        // and now that list becomes empty,
        // increase minFreq
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        // If list for newFreq already exists
        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt+1];
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);    // Increase frequency
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0) return;
        // If key already exists
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);    // Update frequency
        } else {
            // If cache is full
            if(curSize == maxSizeCache)
            {
                // Remove LRU node from minFreq list
                List* list = freqListMap[minFreq];
                Node* nodeToRemove = list->tail->prev;
                keyNode.erase(nodeToRemove->key);
                list->removeNode(nodeToRemove);
                curSize--;
            }
            curSize++;  
            // new values has to be added, not there previously
            minFreq = 1;    // New node always has frequency 1
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};
// Time: O(1), SC: O(capacity)
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */