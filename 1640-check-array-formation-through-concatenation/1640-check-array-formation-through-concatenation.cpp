class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    std::vector<bool> mark(pieces.size(), false);
        
        int ia = 0;
        while (ia < arr.size())
        {
            bool found = false;
            for (int i = 0; i < pieces.size(); i++)
            {
                if (!mark[i] && arr[ia] == pieces[i][0])
                {
                    for (int ip = 0; ip < pieces[i].size(); ip++, ia++)
                    {
                        if (arr[ia] != pieces[i][ip])
                            return false;
                    }
                    mark[i] = true;
                    found = true;
                }
            }
            if (!found)
                return false;
        }
        
        return true;
  }
};