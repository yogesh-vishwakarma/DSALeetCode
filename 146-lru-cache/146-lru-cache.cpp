class node { // our Doubly LL node which will contains 
    public:
        int key;
        int val;
        node* next;
        node* prev;
    node(int _key, int _val) {
        key = _key;
        val = _val; 
    }
};

class LRUCache {
public:
    node* head = new node(-1,-1); // head of LRU functionality
    node* tail = new node(-1,-1); // tail of LRU Functionality
    int cap;                      // max size
    unordered_map<int, node*>m;   // cache
    
    LRUCache(int capacity) { // initializing the cache
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {   // adding new node at start of Doubly LL cause it's least recently used
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) { // removing curr node from Doubly LL
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if (m.find(key_) != m.end()) {// if we found key in cache
            node* resnode = m[key_];  
            int res = resnode->val;  // returning key value
            // now we will update the key,value position to be recent
            m.erase(key_);  // deleting the cache address
            deletenode(resnode); // deleting the curr node
            addnode(resnode); // adding same node after head
            m[key_] = head->next; // adding new node address to cache
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()) { // if key already exist
            node* existingnode = m[key_];
            m.erase(key_);  // removing curr node value from cache cause it needs to be updated
            deletenode(existingnode); // deleting the curr node
        }
        if(m.size() == cap) { // if capacity is full
          m.erase(tail->prev->key); // erase the last value from cache
          deletenode(tail->prev);   // remove last node from linked list
        }
        
        addnode(new node(key_, value)); // adding the node after head
        m[key_] = head->next; // inserting node addresss in cache
    }
};