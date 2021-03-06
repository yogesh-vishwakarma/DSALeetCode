class Solution {
public:
    // https://leetcode.com/problems/number-of-matching-subsequences/discuss/117634/Efficient-and-simple-go-through-words-in-parallel-with-explanation
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<const char*> waiting[128];
        for (auto &w : words)
            waiting[w[0]].push_back(w.c_str());
        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto it : advance)
                waiting[*++it].push_back(it);
        }
        return waiting[0].size();
    }
    /*
    - Create an vector that stores indices for each character a-z in string S
    - Then for each word in words array, do a binary search for next index for current character in word 
      that is greater than the index we last found for the alst character
    - If it doesn't exist, word doesn't exist, otherwise continue to search for word
    
    */
    int numMatchingSubseq2 (string S, vector<string>& words) {
		vector<vector<int>> alpha (26);
		
        for (int i = 0; i < S.size (); ++i) 
            alpha[S[i] - 'a'].push_back (i);
		
        int res = 0;

		for (const auto& word : words) {
			int x = -1;
			bool found = true;

			for (char c : word) {
				auto it = upper_bound (alpha[c - 'a'].begin (), alpha[c - 'a'].end (), x);
				if (it == alpha[c - 'a'].end ()) 
                    found = false;
				else x = *it;
			}

			if (found)
                res++;
		}
		return res;
	}

};