class Solution {
public:
   vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	
	// create a min heap of pair of index of nums1 and nums2
	// compare function is based on sum of elements from [nums1[index] and nums2[index]] so it will always keep 
	// the index of those pairs at the top which has the minimum sum.
	
        auto compare=[&](auto&a,auto&b){return (nums1[a.first]+nums2[a.second])>(nums1[b.first]+nums2[b.second]);};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compare)> pq(compare);
		
		// push {0,0} index of nums1 and nums2
        pq.push({0,0});
        
		vector<vector<int>> ans;
        
		while(!pq.empty()&&k--)
        {
            auto [x,y]=pq.top();pq.pop();
            ans.push_back({nums1[x],nums2[y]});
			
            if(y==0&&x<nums1.size()-1) pq.push({x+1,y});
            if(y<nums2.size()-1) pq.push({x,y+1});
        }
        return ans;
    }
};