class Solution {
    bool find(vector<int>&nums, int val) {
		int s = 0;
		int e = nums.size()-1;
		
		while (s <= e) {
			int mid = s + (e-s)/2;
			if (nums[mid] == val) {
				nums.erase(nums.begin()+mid);
				return true;
			} else if (nums[mid] < val)
				s = mid+1;
			else
				e = mid-1;
		}
		
		return false;
	}
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
			sort(nums1.begin(), nums1.end());
			sort(nums2.begin(), nums2.end());
			
			int l1 = nums1.size();
			int l2 = nums2.size();
			
			vector<int>ans;
			
			if (l1 < l2) {
				for (int i = 0; i < l1; i++)
					if (find(nums2, nums1[i]))
						ans.push_back(nums1[i]);
			} else {
				for (int i = 0; i < l2; i++)
					if (find(nums1, nums2[i]))
						ans.push_back(nums2[i]);
			}
			
			return ans;
    }
};