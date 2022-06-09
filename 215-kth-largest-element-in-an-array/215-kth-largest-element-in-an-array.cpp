class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;k--;
        for(int i(0); i < nums.size();i++)
            pq.push(nums[i]);
        while(k--)
            pq.pop();
        return pq.top();
    }
};