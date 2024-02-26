class Solution {
public:
    int removeDuplicates(vector<int>& arr)
    // {
    //     int i = 0, n=arr.size();
    //     for (int j = 1; j < n; j++) {
    //         if (arr[i] != arr[j]) {
    //         i++;
    //         arr[i] = arr[j];
    //         }
    //     }
    //     return i + 1;
    // }
    {
        int k = 0,n = nums.size();
        for(int i=0;i<n;i++){
            int j = i;
            while(j<n and nums[i]==nums[j]){
                j++;
            }
            nums[k++] = nums[i];
            i = j -1;
        }
        return k;
    }
};