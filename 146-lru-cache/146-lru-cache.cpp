class LRUCache {
private:
    queue<pair<int,int>> q; // <key, seq>
    unordered_map<int,pair<int,int>> m; // <key, <value, seq>>
    int cap, seq;
public:
    LRUCache(int capacity):cap(capacity),seq(0) {
        
    }
    
    int get(int key) {
        if (m.find(key)!=m.end()) {
            m[key].second = ++seq;
            q.push({key, seq});
            return m[key].first;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key)!=m.end()){
            m[key] = {value, ++seq};
            q.push({key, seq});
        }
        else {
            if (cap==0){
                while(m[q.front().first].second > q.front().second) q.pop();
                m.erase(q.front().first); q.pop();
                ++cap;
            }
            m[key] = {value, ++seq};
            q.push({key,seq});
            --cap;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */