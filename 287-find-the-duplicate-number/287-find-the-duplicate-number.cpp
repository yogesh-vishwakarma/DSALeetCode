class Solution {
public:
    /*
    Because the indexes are in range (1,n) and elements also must be in range (1,n);
    we can see that simillar elements have diffrent index, diffrent index have simillar elements
    so if we use elements as indexes we will come for same index multiple times.
    so we can  see it as a circular path.
    exx:
    0, 1, 2, 3, 4
    3, 1, 3, 4, 2
    
    0th idex 3-> 3rd index 4-> 4th index 2-> 2nd index 3->3rd index 4-> 4th index 2 (looping)
    it's like circular linked list, so can use that approach here.
    */
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