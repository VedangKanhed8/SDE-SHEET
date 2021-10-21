class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        
        for(int r = 0 ; r < numRows ; r++) {
            res[r].resize(r+1,1);
            for(int c = 1 ; c < r ; c++) {
                res[r][c] = res[r-1][c-1] + res[r-1][c];
            }
        }
        
        return res;
    }
};
