class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>> ans;
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(),intervals.end());
        vector<int>temp = intervals[0];
        
        for(auto it:intervals){
            if(it[0]<=temp[1])
                temp[1]=max(it[1],temp[1]);
            else{
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
    
    
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>> st;
        st.push({intervals[0][0],intervals[0][1]});
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(st.top().second>=intervals[i][0])
                st.top().second=intervals[i][1]>st.top().second? intervals[i][1]:st.top().second; 
            else
               st.push({intervals[i][0],intervals[i][1]});
        }
        vector<int> p;
        while(!st.empty()){
            p.push_back(st.top().first);
            p.push_back(st.top().second);
            ans.push_back(p);
            p.clear();
            st.pop();    
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};