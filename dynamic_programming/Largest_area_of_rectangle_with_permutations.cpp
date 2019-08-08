int Solution::solve(vector<vector<int> > &A) {
    int row = A.size();
    int column = A[0].size();

    vector<vector<int> > count_one(row, vector<int>(column, 0));
    for (int i = 0; i < column; i++) {
        for (int j = row - 1; j >= 0; j--) {
            if (A[j][i] == 0) {
                count_one[j][i] = 0;
            } else {
                if (j == row - 1) {
                    count_one[j][i] = 1;
                } else {
                    count_one[j][i] = 1 + count_one[j + 1][i];
                }
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < row; i++) {
        sort(count_one[i].begin(), count_one[i].end());
        for (int j = 0; j < column; j++) {
            ans = max(ans, count_one[i][j] * (column - j));
        }
    }
return ans;
}



