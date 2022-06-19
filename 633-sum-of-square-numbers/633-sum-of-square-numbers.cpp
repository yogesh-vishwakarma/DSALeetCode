class Solution {
public:
   // using binary_search to find the floor sqrt . 
// I intentionally wrote binary search here you could use library ones
int sqrt_num(int c)
    {
        int low = 1; 
        int high = c;  
        int ans = 0; 
        
        while(low <= high){
            long long mid = (high-low)/2 + low;  
            if(mid * mid == c)
                return mid; 
            else if(mid * mid < c){
                ans = mid; 
                low = mid + 1; 
            }
            else if(mid * mid > c){
                high = mid-1; 
            }
        }
        return ans; 
    }
    
    bool judgeSquareSum(int c) {
        // we use two pointer algorithm to find the pair of numbers 
        int sqrt_c = sqrt_num(c); 
        
        long long low = 0; 
        long long high = sqrt_c;  
        
        while(low <= high){
            if(low*low + high*high < c){
                low++;
            }
            else if(low * low + high * high > c){
                high--;
            }
            else if(low * low + high * high == c){
                return true; 
            }
        }
        return false; 
    }
};