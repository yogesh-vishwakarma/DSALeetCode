class Solution {
public:
    int uniquePaths(int m, int n) {
        double ans =1;
        n = (n-1) + (m-1);
		int r = m-1;
		for (int i = 1; i <= r; ++i) // nCr formula
			ans =ans* (n-r+i)/i;
	return (int)ans;
    }
}; 