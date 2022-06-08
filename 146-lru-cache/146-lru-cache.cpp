class Node
{
    public:
        int key;
    int val;
    Node *next = NULL;
    Node *prev = NULL;
};

class LRUCache
{
    private:
    
    int cap; //to store capacity of cache
    int size = 0; // number of element in cache
    Node *head = NULL; // initialize head of list to null
    Node *tail = NULL; // intitialize tail to null
    unordered_map<int, Node*> mp; //initialize hash map instanse

//     to update the Node
    void updateNode(Node* &node)
    {
        if (tail == node)
        {
            head->prev = tail;
            tail->next = head;
            head = tail;
            tail = tail->prev;
            tail->next = NULL;
            return;
        }
        if (head == node)
        {
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        head->prev = node;
        node->prev = NULL;
        node->next = head;
        head = node;
    }

//     to add new node to the list
    void addNode(Node *node)
    {
        head->prev = node;
        node->next = head;
        head = node;
        return;
    }

    public:
//     constructore initialize cache capacity
        LRUCache(int capacity)
        {
            cap = capacity;
        }

// get the val if found
    int get(int key)
    {
//         fist check in hash map is their any key in list
        auto it = mp.find(key);
    
//         if exist key then update the status of key
        if (it != mp.end())
        {

            updateNode(it->second);
            return it->second->val;
        }
//         else return -1
        return -1;
    }

//     to add new key , value in cache
    void put(int key, int value)
    {
//         check if the key already exist or not
        auto it = mp.find(key);

//         if key exist update its value and usage status
        if (it != mp.end())
        {
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