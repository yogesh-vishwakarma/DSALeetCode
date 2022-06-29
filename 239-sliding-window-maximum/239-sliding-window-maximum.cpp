class Solution {
public:
    /* Optimal Approach*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // support variables
        int len = nums.size() - k + 1, higherValues[k], startPos = 0, endPos = 0;
        vector<int> res(len);
        // preparing dq with the first k - 1 elements
        k--;
        for (int i = 0; i < k; i++) {
            while (endPos != startPos && nums[higherValues[endPos - 1]] <= nums[i]) endPos = endPos - 1;
            higherValues[endPos++] = i;
        }
        k++;
        // parsing through nums
        for (int i = 0, n = k - 1; i < len; i++, n++) {
            // popping smaller values
            while (endPos != startPos && nums[higherValues[endPos ? endPos - 1 : k - 1]] <= nums[n]) endPos = endPos ? endPos - 1 : k - 1;
            // adding the current index n
            higherValues[endPos++] = n;
            if (endPos == k) endPos = 0;
            // updating res
            res[i] = nums[higherValues[startPos]];
            // popping the first element out
            if (higherValues[startPos] == i) startPos = (startPos + 1) % k;
        }
        return res;
    }
    /*Dq approach*/
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
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