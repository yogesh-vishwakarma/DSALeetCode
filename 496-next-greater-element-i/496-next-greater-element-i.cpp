class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ump;
        stack<int> st;// int stPointer (0);
        for(int el : nums2){
            while( !st.empty() && st.top() < el){
                ump[st.top()] = el; 
                // here we are updating biggest element for all the smallest element from curr
                st.pop();
            } 
            st.push(el);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i] = (ump.find(nums1[i])!=ump.end())? ump[nums1[i]] : -1;
        }
        return nums1;
    }
};