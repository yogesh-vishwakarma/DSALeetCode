class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int p1 = 0, p2 = 0; int minCommon = -1;
        while(p1 < len1 && p2 < len2){
            if(nums1[p1] == nums2[p2]){
                return nums1[p1];
            }else if(nums1[p1] > nums2[p2]){
                p2++;
            }else{
                p1++;
            }
        }
        return minCommon;
    }
};