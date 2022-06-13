class Solution {
public:
    int arrangeCoins(int n) {
        int left(1), right(n);
        while(left<=right){
            long mid = left + (right-left)/2 ;
            long coinsNeeded = mid*(mid+1)>>1 ;
            if(coinsNeeded<= n)
                left = mid+1;
            else
                right = mid-1;
        }
        return left-1;
    }
};