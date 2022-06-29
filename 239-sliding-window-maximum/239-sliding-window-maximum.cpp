class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;vector<int> ans;
        // we are storing indexes in dq
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) 
                dq.pop_front();
            
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i); // inserting curr index
            if (i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    
/*
 [1,3,-1,-3,5,3,6,7] k = 3
  0,1, 2, 3,4,5,6,7
    i : queues
    0: [0]
    1: [0]->[]->[1]
    2: [1]->[1,2]                               ans.add(nums[1])
    3: [1,2]->[1,2,3]                           ans.add(nums[1])
    4: [1,2,3]->[1,2,3,4]->[2,3]->[2]->[]->[4]  ans.add(nums[4])
    5: [4]->[4,5]                               ans.add(nums[4])
    6: [4,5]->[4]->[]->[6]                      ans.add(nums[6])
    7: [6]->[]->[7]                             ans.add(nums[7])
*/
};