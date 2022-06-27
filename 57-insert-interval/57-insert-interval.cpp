class Solution {
public:
    vector<vector<int>> insert1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return myInsert(intervals, newInterval);
    }
    
    vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>res.back()[1])
                res.push_back(intervals[i]);
            else
                res.back()[1]=max(res.back()[1],intervals[i][1]);
        }
        return res;
        
    }
    
    vector<vector<int>> insert(vector<vector<int>>& ints, vector<int>& ni, int i = 0) {
        vector<vector<int>> res;
        for (; i < ints.size() && ints[i][0] <= ni[1]; ++i) {
            if (ints[i][1] < ni[0])
                res.push_back(ints[i]);
            else {
                ni[0] = min(ni[0], ints[i][0]);
                ni[1] = max(ni[1], ints[i][1]);
            }
        }
        res.push_back(ni);
        res.insert(end(res), begin(ints) + i, end(ints));
        return res;
    }
    
private:
    vector<vector<int>> myInsert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // binary search for the insertion location.
        int beg_index = -1, end_index = -1;
        bool beg_in_range = false, end_in_range = false;

        int bs_beg = 0, bs_end = intervals.size() - 1;
        // find start location
        while (bs_beg <= bs_end) {
            int mid_index = (bs_beg + bs_end) / 2;
            if (newInterval[0] < intervals[mid_index][0]) {
                // Less than, search other half of range
                bs_end = mid_index - 1;
            } else if (newInterval[0] > intervals[mid_index][1]) {
                bs_beg = mid_index + 1;
            } else {
                beg_index = mid_index;
                beg_in_range = true;
                break;
            }
        }
        if (!beg_in_range) {
            beg_index = bs_beg;
        }

        bs_beg = 0, bs_end = intervals.size() - 1;
        while (bs_beg <= bs_end) {
            int mid_index = (bs_beg + bs_end) / 2;
            if (newInterval[1] < intervals[mid_index][0]) {
                // Less than, search other half of range
                bs_end = mid_index - 1;
            } else if (newInterval[1] > intervals[mid_index][1]) {
                bs_beg = mid_index + 1;
            } else {
                end_index = mid_index;
                end_in_range = true;
                break;
            }
        }
        if (!end_in_range) {
            end_index = bs_beg;
        }
        vector to_add = {(beg_in_range) ? intervals[beg_index][0] : newInterval[0],
                         (end_in_range) ? intervals[end_index][1] : newInterval[1]};
        vector<vector<int>> solution;
        solution.insert(solution.end(), intervals.begin(), intervals.begin() + beg_index);
        solution.push_back(to_add);
        solution.insert(solution.end(), intervals.begin() + end_index + (end_in_range ? 1 : 0), intervals.end());
        return solution;
    }
};