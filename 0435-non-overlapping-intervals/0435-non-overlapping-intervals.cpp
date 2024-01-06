class Solution {
public:

    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        int len = intervals.size();
        if(len == 0){
            return result;
        }
        sort(intervals.begin(), intervals.end());
        int ptr = 0;
        for(int i = 1; i < len; i++){
            if (intervals[ptr][1] > intervals[i][0]) {
                result++;
                // Choose the interval with the larger end value to remove
                if (intervals[ptr][1] > intervals[i][1]) {
                    ptr = i;
                }
            } else {
                ptr = i;
            }
        }
        return result;
    }
};