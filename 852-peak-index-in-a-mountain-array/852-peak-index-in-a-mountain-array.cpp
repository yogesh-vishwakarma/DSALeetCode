class Solution {
public:    
    int peakIndexInMountainArray(vector<int>& arr) {
        int left(0), right(arr.size()-1);
        
        while(left<=right){
            int mid = (left+right) >>1;
            if( arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
                return mid;
            else if( arr[mid] < arr[mid+1] && arr[mid] > arr[mid-1])
                left = mid;
            else if( arr[mid] > arr[mid+1] && arr[mid] < arr[mid-1])
                right  = mid;
        }
        return -1;
    }
};