class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        vector<int> result;

        for(int i=0;i<nums1.size();i++){

          if (map1.find(nums1[i]) == map1.end())
            map1[nums1[i]]=1;
          else 
            map1[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){

          if (map2.find(nums2[i]) == map2.end())
            map2[nums2[i]]=1;
          else 
            map2[nums2[i]]++;
        }

        for(auto itr:map1){
          if(map2.find(itr.first) != map2.end()){
            int i=min(map2[itr.first], map1[itr.first]);
            while(i--){
              result.push_back(itr.first);
            }
          }
        }
        return result;
    }
};