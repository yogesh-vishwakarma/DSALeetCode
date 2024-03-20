class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int endPtr(m+n), p1 = m-1, p2 = n-1;
        for(int i = m + n -1; i>=0; i--){
            cout << nums1[i] <<" ";
            nums1[i] = nums1[p1] > nums2[p2]? nums1[p1--] : nums2[p2--];
        }
    }
};