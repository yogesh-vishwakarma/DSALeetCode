class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string bits = bitset<32>(n).to_string();
        reverse(bits.begin(), bits.end());
        return stoul(bits, nullptr, 2);
    }
};