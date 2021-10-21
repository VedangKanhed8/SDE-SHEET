// Key Idea : use first element of every row and every column as a flag to determine if it contains zero
// Corner Case : as matrix[0][0] is common to both so use extra variable for determining column 

class Solution {
public :
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        bool is_col_zero = false;
        
        for(int i = 0 ; i < row ; i++) {
            
            if(matrix[i][0] == 0) is_col_zero = true;
            
            for(int j = 1 ; j < col ; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1 ; i < row ; i++) {
            for(int j = 1 ; j < col ; j++) {
                if(matrix[i][0] == 0 or matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        if(!matrix[0][0]) {
            for(int c = 0 ; c < col ; c++) matrix[0][c] = 0;
        } 
        if(is_col_zero) {
            for(int r = 0 ; r < row ; r++) matrix[r][0] = 0;
        }
    }
};
