class Solution {
public:
    /*
    Rotate = transpose + reverse each row
    
    transpose = (transposing means changing columns to rows and rows to columns)
    
    */
    void rotate(vector<vector<int>>& matrix1) {
        int cols=matrix1.size();
        int rows=matrix1[0].size();
        for (int i = 0; i < cols; ++i){
	        	for (int j = 0; j < i ; ++j){
	        			swap(matrix1[i][j],matrix1[j][i]);
	        	}
	        }
	        for (int i = 0; i < rows; ++i){
	        	for (int j = 0; j<rows/2; ++j){
	        		swap(matrix1[i][j],matrix1[i][rows-1-j]);       		
	        	}
	        }
    }
};