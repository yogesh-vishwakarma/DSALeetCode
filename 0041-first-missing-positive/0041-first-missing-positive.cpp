class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] > 0 && nums[i] < n){
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
    }
};

// int firstMissingPositive(vector<int>& nums) {
//         int curr = 0, n = nums.size(); // take 2 pointers
//         while( curr < n){ // iterating through nums array
//             // if indexed el is >0 && <=n && not equal to index
//             if(nums[curr] > 0 && nums[curr] <= n && nums[curr] != nums[nums[curr] - 1])
//                 swap(nums[curr],nums[nums[curr] - 1]); // swap then to change into matching
//             else
//                 curr++;
//         }
//         /* 
//         nums:              [3,  4,-1, 1, 7, 8, 9, 11]
//         indexes+1:          1   2  3  4  5  6   7  8
//         after cyclic sort: [1, -1, 3, 4, 9, 11, 7, 8]
//         we can see that at inddex 2 the element is -1 so 2 is missing then ans = 2;
//         */
//         for(int i = 0;i<n;i++){
//             if(nums[i] != i + 1){
//                 return i + 1;
//             }
//         }
//         return n + 1;
//     }