// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n,res;
        while (l <= r){
            if(isBadVersion(l)){
                return l;
            }
            int mid = l +(r-l)/2;
            if(isBadVersion(mid)){
                r = mid-1;
                res = mid;
                continue;
            }
            l = mid + 1;
        }
        return res;
    }
};