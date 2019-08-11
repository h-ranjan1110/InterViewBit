int Solution::isMatch(const string A, const string B) {
    int l = A.length();
    int m = B.length();
    bool dp[l + 1][m + 1];
    

    for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0 || (i == 0 && j == 1 && B[j] == "*") || (j == 0 && i == 1 && A[i] == "*")) {
                dp[i][j] = true;
            } else if (i == 0 || j == 0) {
                dp[i][j] = false;
            }
            if(A[i] == B[j] && (A[i] != '*' || A[i] != '?')) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if(A[i] != B[j] && (A[i] != '*' || A[i] != '?')) {
                dp[i][j] = false;
            } else if(B[j] == '*' || A[i] == '*') {
                dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
            } else if(A[i] == '?' || B[j] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[l][m];
}