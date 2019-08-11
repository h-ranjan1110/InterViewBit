

    int Solution::arrange(string A, int B) {
        int n = A.length();
        // cout<<n;
        if (n < B) return -1;
        int dp[n + 1][B + 1];
        int wc = 0;
        int bc = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][1] = 0;
            if (A[i - 1] == 'W') {
                wc += 1;
            } else {
                bc += 1;
            }
            dp[i][1] = wc*bc;
            // cout << i << " "<<1<<"::"<<dp[i][1]<<endl;
        }
        int prod[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            prod[i][i] = 0;
            for (int j = i + 1; j <= n; j++) {
            int wc = 0;
            int bc = 0;
                for (int k = i; k <= j; k++) {
                    if (A[k - 1] == 'W') {
                    wc += 1;
                } else {
                    bc += 1;
                }
                }
                prod[i][j] = wc*bc;
                // cout << i << " "<<j<<"::"<<prod[i][j]<<endl;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= B; j++) {
                 // do not give int max value as it can over flow some times. or use long long if giving int max.
                if (i == 1) dp[i][j] = 1000000009;
                else if (j > i) dp[i][j] = 1000000009;
                else {
                    int minprod = 1000000009;
                for (int k = i - 1; k >= 1; k--) {
                    minprod = min(minprod, dp[k][j - 1] + prod[k + 1][i]);
                }
                dp[i][j] = minprod;
                }
                
                // cout <<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[n][B];
    }

