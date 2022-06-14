class Solution {
public:
    vector<int> twoSum(vector<int>&arr, int t) {
        
        for(int i=0;i<arr.size();i++){
            int k = t-arr[i];
            int ind = upper_bound(arr.begin(),arr.end(),k)-arr.begin();
            
            if(arr[ind-1]==k and ind-1!=i)
                return {min(i+1,ind),max(i+1,ind)};
        }
        return {};
        
    }
};