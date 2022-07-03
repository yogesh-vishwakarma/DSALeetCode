class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // int n1 = nums1.size(), n2=nums2.size();
        // int p1(0), p2(0), x=0, y=0;
        // while(p1+p2 <= (n1+n2)/2 ){
        //     y=x;
        //     if( (p1 < n1 && nums1[p1] < nums2[p2]) || p2>= n2 )
        //         x=nums1[p1++];
        //     else
        //         x=nums2[p2++];
        // }
        
        
        
        int n1 = nums1.size(), n2=nums2.size();
        int j=0,k=0, x=0, y=0;
        while(j+k<=((n1+n2)/2)){
                y=x;
            (k>=n2 || (j<n1 && nums1[j]<nums2[k]))? x=nums1[j++] : x=nums2[k++];
        }
        return ((n1+n2)%2)? (double)x : (double)(x+y)/2;
    }
};