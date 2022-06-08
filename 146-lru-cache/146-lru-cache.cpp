class Node{ // doubly linked list
    public:
        int key;
        int val;
        Node *next = NULL;
        Node *prev = NULL;
};

class LRUCache{
    private:
    
    int cap; //to store capacity of cache
    int size = 0; // number of element in cache
    Node *head = NULL; // initialize head of list to null
    Node *tail = NULL; // intitialize tail to null
    unordered_map<int, Node*> mp; //initialize hash map instanse

    void updateNode(Node* &node){ // to update the Node
        if (tail == node){
            head->prev = tail;
            tail->next = head;
            head = tail;
            tail = tail->prev;
            tail->next = NULL;
            return;
        }
        if (head == node){
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        head->prev = node;
        node->prev = NULL;
        node->next = head;
        head = node;
    }

    void addNode(Node *node){ // to add new node to the list
        head->prev = node;
        node->next = head;
        head = node;
        return;
    }

    public:
        LRUCache(int capacity){ // constructore initialize cache capacity
            cap = capacity;
        }

        int get(int key){ // get the val if found
            auto it = mp.find(key);

            if (it != mp.end()){
                updateNode(it->second);
                return it->second->val;
            }
            return -1;
        }

        void put(int key, int value){
            auto it = mp.find(key);
            
            if (it != mp.end()){
                it->second->val = value;
                updateNode(it->second);
                return;
            }

    //         if head is null means list is empty
            if (head == NULL)
            {
    //             create new node
                Node *newNode = new Node;
                newNode->key = key;
                newNode->val = value;
    //             add new node key,Node pair to hash map
                mp.insert({ key,
                    newNode });
    //             assign newNode value to head
                head = newNode;
    //             assign newNode value to tail as there is only one node
                tail = newNode;
    //             increse number of element in cache
                size++;
                return;
            }

    //         if size is less then cache no need to delete lru item simply add new node to list
            if (size < cap)
            {
    //             delcare new node
                Node *newNode = new Node;
                newNode->key = key;
                newNode->val = value;

    //             add new node key,Node pair to hash map
                mp.insert({ key,
                    newNode });
    //             add node to list
                addNode(newNode);
    //             increse number of element in cache            
                size++;
                return;
            }

    // if cache is full remove element from tail lru
            mp.erase(tail->key);
            head->prev = tail;
            tail->next = head;
            head = tail;
            tail = head->prev;
            tail->next = NULL;
            head->key = key;
            head->val = value;
            mp.insert({ key,
                head });
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */