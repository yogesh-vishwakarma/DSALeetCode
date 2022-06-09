class Solution {
public:
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int> pq;k--;
    //     for(int i(0); i < nums.size();i++)
    //         pq.push(nums[i]);
    //     while(k--)
    //         pq.pop();
    //     return pq.top();
    // }
    int findKthLargest(vector<int>& nums, int k) {
        int low = -1005, high = 1e4+2;       
        while(low < high) {
            int mid = low+(high-low)/2;
            int cnt = 0;
            for(auto i:nums) if(i>mid)cnt++;
            if(cnt<k)high = mid;else low = mid+1;
        }
        return low;
    }
};