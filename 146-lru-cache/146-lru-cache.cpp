class LRUCache{
    /*
    
    When we access an item in the cache it moves to the front of the list as it is the most recently used item.

    When we want to remove an item we remove it from the last of the list as it is the least recently used item in the cache.
    
    When we insert an item we insert it into the front of the list as it is the most recently used item.

    The idea is to store the keys in the map and its corrosponding values into the list...
    
    Note : splice() function here takes the element at the m[key] and places it at the beginning of the list..
    
    
    */
    public:
        list<pair<int,int>> l;
        unordered_map<int,list<pair<int, int>>::iterator> m;
        int size;
        LRUCache(int capacity){size=capacity;}
        
        int get(int key){
            if(m.find(key)==m.end())
                return -1;
            l.splice(l.begin(),l,m[key]);
            return m[key]->second;
        }
        void put(int key, int value){
            if(m.find(key)!=m.end()){
                l.splice(l.begin(),l,m[key]);
                m[key]->second=value;
                return;
            }
            if(l.size()==size){
                auto d_key=l.back().first;
                l.pop_back();
                m.erase(d_key);
            }
            l.push_front({key,value});
            m[key]=l.begin();
        }
};



// class LRUCache2 {
// private:
//     queue<pair<int,int>> q; // <key, seq>
//     unordered_map<int,pair<int,int>> m; // <key, <value, seq>>
//     int cap, seq;
// public:
//     LRUCache(int capacity):cap(capacity),seq(0) {}// parameterized constructor
    
//     int get(int key) {
//         if (m.find(key)!=m.end()) {
//             m[key].second = ++seq;
//             q.push({key, seq});
//             return m[key].first;
//         }
//         else return -1;
//     }
    
//     void put(int key, int value) {
//         if (m.find(key)!=m.end()){
//             m[key] = {value, ++seq};
//             q.push({key, seq});
//         }
//         else {
//             if (cap==0){// if no current capacity
//                 // we are removing extra operations
//                 while(m[q.front().first].second > q.front().second)
//                     q.pop();
//                 // we found the least recently used opration, so remove it and increase cap.
//                 m.erase(q.front().first);
//                 q.pop();
//                 ++cap;
//             }
//             m[key] = {value, ++seq};
//             q.push({key,seq});
//             --cap;
//         }
//         queue<pair<int,int>> printQ = q;
//         while(!printQ.empty())
//             cout << q.front().first <<" "<<q.front().second <<endl;
//         cout << endl;
//     }
// };