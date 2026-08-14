class LRUCache {
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v){
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }

    };
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void removenode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertathead(Node* node){
        node->next = head->next;
        head->next = node;
        node->prev = node->next->prev;
        node->next->prev = node;
    }
    
    int get(int key) {
        if(mp.count(key)){
            removenode(mp[key]);
            insertathead(mp[key]);
            return mp[key]->val;

        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->val = value;
            removenode(mp[key]);
            insertathead(mp[key]);
        }
        else{
            if (mp.size() >= capacity){
                mp.erase(tail->prev->key);
                removenode(tail->prev);
                Node* whatever = new Node(key, value);
                insertathead(whatever);
                mp[key] = whatever;
            }
            else{
                Node* newnode = new Node(key,value);
                insertathead(newnode);
                mp[key] = newnode;
            }
        }
        
    }
};
