int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    vector<vector<int> > row_sum(n, vector<int>(m));
    row_sum = A;
    
    for (int i = 0; i < n; i++) {
        for (int j = m - 2; j >= 0; j--) {
            row_sum[i][j] = A[i][j] + row_sum[i][j + 1];
        }
    }
    vector<vector<int> > matrix_sum(n, vector<int>(m, 0));
    int ans = INT_MIN;
    for( int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int row_val = 0;
            int col_val = 0;
            if (i != m - 1) {
                row_val = row_sum[j][i + 1];
            }
            if (j !=   n - 1) {
                col_val = matrix_sum[j + 1][i];
            }
            matrix_sum[j][i] = A[j][i] + row_val + col_val;
            ans = min(ans, matrix_sum[j][i]);
        }
    }
}
