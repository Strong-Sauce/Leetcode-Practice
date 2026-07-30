class LRUCache {
private:
    struct Node{
        int key; int value;
        Node* next;
        Node* prev;
        Node(int k, int v): key(k), value(v), next(NULL), prev(NULL){}
    };
    Node* head;
    Node* tail;
    map<int, Node*> mp;
    int limit;

    void insertAtHead(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void del(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
    }
public:
    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            del(node);
            insertAtHead(node);
            return node->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key]->value = value;
            get(key);
        }
        else{
            if(mp.size() >= limit){
                mp.erase(tail->prev->key);
                del(tail->prev);
            }
            mp[key] = new Node(key,value);
            insertAtHead(mp[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */