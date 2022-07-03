class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2=nums2.size();
        // int p1(0), p2(0);
        // while(p1+p2 < (n1+n2)/2 ){
        //     if(nums1[p1] < nums2[p2])
        //       (p1<n1)? ++p1: ++p2;
        //     else
        //         (p2<n2)? ++p2: ++p1;
        //     cout <<p1<<" "<<p2<<endl;
        // }
        // double ans = (nums1[p1]+nums2[p2])/2;
        // return ans;
        int j=0,k=0;
        int x=0, y=0;
        while(j+k<=((n1+n2)/2)){
            if(k>=n2 || (j<n1 && nums1[j]<nums2[k])){
                y=x;
                x=nums1[j++];
            }
            else{
                y=x;
                x=nums2[k++];
            }
        }
        if((n1+n2)%2==0)
            return (double)(x+y)/2;
        return (double)x;
        
    }
};