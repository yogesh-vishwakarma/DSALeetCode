class Solution {
public:
    int numTrees(int n) {
        uint64_t ans = 1;
        for (int i = 1; i < n + 1; i++) {
            ans *= n + i;
            ans /= i;
        }
        return ans / (n + 1);
    }
};