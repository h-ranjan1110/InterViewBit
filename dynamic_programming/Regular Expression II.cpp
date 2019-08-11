    int Solution::isMatch(const string A, const string B) {
        int l = A.length();
        int m = B.length();
        vector<vector<bool> > dp(l + 1, vector<bool> (m +1, false));
        // bool dp[l + 1][m + 1];
        // memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        if(B[0] == '*') dp[0][1] = true;
        for (int j = 2; j <= m; j++) 
            if (B[j - 1] == '*') 
                dp[0][j] = dp[0][j - 2];
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= m; j++) {
                if(B[j - 1] == '*' && j > 1 && (A[i - 1] == B[j - 2] || B[j - 2] == '.')) {
                    dp[i][j] = dp[i-1][j]||dp[i][j-2]||dp[i - 1][j - 2];
                } else if(B[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                } else if(A[i - 1] == B[j - 1] || B[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        if (dp[l][m] == true) {
            return 1;
        } else {
            return 0;   
        }
    }

