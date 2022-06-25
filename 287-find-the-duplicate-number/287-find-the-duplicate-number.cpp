class Solution {
public:
    int findDuplicate1(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        
        while(low <=  high){
            int cnt = 0;
            int mid = (low + high)/2;
            for(int n : nums)
                if(n <= mid)
                    ++cnt;
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
        }
        return low;
    }
    
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int slow = 0;
        int fast = 0;
        while(slow<len && fast <len) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        }
        int curr = 0;
        while(curr!=slow) {
            curr = nums[curr];
            slow = nums[slow];
        }
        return curr;
    }
};