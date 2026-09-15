class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> cols(n, 0), diag1(2*n, 0), diag2(2*n, 0);
        backtrack(0, n, cols, diag1, diag2, count);
        return count;
    }
    
private:
    void backtrack(int row, int n,
                   vector<int>& cols, vector<int>& diag1, vector<int>& diag2,
                   int& count) {
        if (row == n) {
            count++;
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row+col] || diag2[row-col+n]) continue;
            
            cols[col] = diag1[row+col] = diag2[row-col+n] = 1;
            backtrack(row+1, n, cols, diag1, diag2, count);
            cols[col] = diag1[row+col] = diag2[row-col+n] = 0;
        }
    }
};
