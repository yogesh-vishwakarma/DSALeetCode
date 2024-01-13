class Solution {
  int primes[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
  int modulo = 1e9 + 7;
  unsigned long long int createHash(string s) {
    unsigned long long int key = 1;
    for (char &ch : s) {
      key *= this->primes[ch - 97];
      key %= this->modulo;
    }
    return key;
  }

public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<unsigned long long int, int> map;
    vector<vector<string>> result = {};

    int index = 0;
    for (int i = 0; i < strs.size(); i++) {
      unsigned long long int currentHash = this->createHash(strs[i]);
      // insert into result
      if (map.find(currentHash) == map.end()) {
        map[currentHash] = index;
        index++;
        // enter new item
        result.push_back({strs[i]});
      } else
        // enter existing item
        result[map[currentHash]].push_back(strs[i]);
    }

    return result;
  }
};