int Solution::numDistinct(string A, string B) {
    int l = A.length();
    int m = B.length();
    int dp[l + 1][m + 1];
    for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j != 0) {
                dp[i][j] = 0;
            } else if( j == 0 ) {
                dp[i][j] = 1;
            }else if (A[i - 1] != B[j - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }
    return dp[l][m];
}
