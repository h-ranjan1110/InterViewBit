int Solution::numDecodings(string A) {
    int n = A.length();
    vector <int> dp(n + 1, 0);
    if (A[0] == '0') {
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (A[i - 1] != '0') {
            dp[i] = dp[i - 1];
        }
        if (A[i - 2] == '1' || (A[i - 2] == '2' && (A[i - 1] <= '6'))) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}
