int max(int a, int b) {
    return (a > b)? a : b;
}
int Solution::anytwo(string A) {
    int n = A.length();
    int lcs[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            lcs[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == A[j - 1] && i != j) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    if (lcs[n][n] > 1) {
        return 1;
    } else {
        return 0;
    }
}