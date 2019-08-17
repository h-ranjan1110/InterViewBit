int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    int dp[n];
    
    int maxval = -1000000007;
    for (int i = n - 2; i >= 0;  i--) {
        dp[i] = max(A[i + 1], maxval);
    }
    
    int maxprofit = INT_MIN;
    
    for (int i = 0; i < n - 1; i++) {
        maxprofit = max(maxprofit, dp[i] - A[i]);
    }
    if (maxprofit < 0) return 0;
    else return maxprofit;
    
}
