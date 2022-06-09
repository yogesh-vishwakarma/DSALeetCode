class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    for (int row = 0; row < pieces.size(); row++) {
      auto it = std::find(begin(arr), end(arr), pieces[row][0]);
      for (int col = 0; col < pieces[row].size(); col++) {
        if (it == end(arr)) return false;
        if (*(it++) != pieces[row][col]) return false;
      }
    }
    return true;
  }
};