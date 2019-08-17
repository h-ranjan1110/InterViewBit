int Solution::coinchange2(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(), A.end());
    vector<int> dp(B + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for(int j = A[i]; j <= B; j++) {
            dp[j] += dp[j - A[i]]% 1000007;
            dp[j] = dp[j]% 1000007;
        }
    }
    
    return dp[B]% 1000007;
}
