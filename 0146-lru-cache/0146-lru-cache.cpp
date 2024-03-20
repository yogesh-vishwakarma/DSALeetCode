class LRUCache {
public:
    LRUCache(int capacity): capacity{capacity} {}
    
    int get(int key) {
        if(cache.contains(key)) {
           auto v  = cache[key]->second;

           lru.splice(lru.begin(), lru, cache[key]);

           return v;
        } 

        return -1;
    }
    
    void put(int key, int value) {
        if(cache.contains(key)) {
           auto it = cache[key];

           it->second = value;
           lru.splice(lru.begin(), lru, it);

           return;
        }

        if(cache.size() == capacity) {
            auto retired = lru.back().first;
            cache.erase(retired);
            
            lru.pop_back();
        }
        
        lru.emplace_front(key, value);
        cache[key] = lru.begin();

        return;        
    }

private:
    int capacity{0};
    using Data = std::pair<int, int>;

    std::list<Data> lru{};
    std::unordered_map<int, std::list<Data>::iterator> cache{};
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */