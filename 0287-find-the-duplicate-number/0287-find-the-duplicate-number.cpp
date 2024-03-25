class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // Find the intersection point of the two pointers
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        // Find the entrance of the cycle in linked list
        int ans = nums[0];
        while(ans != slow){
            ans = nums[ans];
            slow = nums[slow];
        }
        return ans;
    }
};