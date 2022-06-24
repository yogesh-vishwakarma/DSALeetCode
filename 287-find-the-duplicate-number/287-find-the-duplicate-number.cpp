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
        int slow = nums[0];
        int fast = nums[0];
        do {
        slow = nums[slow];
        fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
        }
        return slow;
    }
};