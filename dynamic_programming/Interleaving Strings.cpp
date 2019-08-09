int Solution::isInterleave(string A, string B, string C) {
    int l = A.length();
    int m = B.length();
    int n = C.length();
    int dp[l + 1][m + 1];
    if ((l + m) != n) return 0;
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= l; ++i) {
        for (int j = 0; j <= m; ++j) {
            if  (i == 0 && j == 0) {
            dp[i][j] = true;
            // == written in place of = (silly mistake)
            } else if(i == 0 && B[j - 1] == C[j - 1]) {
                     dp[i][j] = dp[i][j - 1]; // make subproblems, do not solve by matching whole substring upto j of b and c
            } else if (A[i - 1] == C[i - 1] && j == 0) {
                     dp[i][j] = dp[i - 1][j];
            } else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[j + i - 1]) {
                dp[i][j] = dp[i][j - 1];
            } else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]){
                dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
            }
        }
    }
    if (dp[l][m] == true) {
         return 1;
    }
     else {
         return 0;
    }
   
}
