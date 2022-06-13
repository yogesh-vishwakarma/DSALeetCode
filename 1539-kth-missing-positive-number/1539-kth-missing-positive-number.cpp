class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int left = 0, right = A.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (A[mid] - 1 - mid < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left + k;
    }
};