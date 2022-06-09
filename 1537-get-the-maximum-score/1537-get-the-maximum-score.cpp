class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        long long ans=0,mod=1e9+7;
        int i=0,j=0;
        long long sum1=0,sum2=0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j])
            {
                sum1+=nums1[i],sum2+=nums2[j];
                ans=(ans+max(sum1,sum2))%mod;
                i++,j++;
                sum1=0,sum2=0;
            }
            else if(nums1[i]<nums2[j])
            {
                sum1+=nums1[i];
                i++;
            }
            else {
                sum2+=nums2[j];
                j++;
            }
        }
        while(i<n)
        {
            sum1+=nums1[i++];
        }
        while(j<m) sum2+=nums2[j++];
        ans=(ans+max(sum1,sum2))%mod;
        return ans;
    }
};