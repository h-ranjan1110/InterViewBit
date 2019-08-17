int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (i == 0) {
                // do nothing.
            } else if (j == 0) {
                A[i][j] = A[i - 1][j] + A[i][j];
                
            } else if (j == A[i].size() - 1) {
               
                A[i][j] = A[i - 1][j - 1] + A[i][j];
            }
            else {
                A[i][j] = min(A[i - 1][j - 1], A[i - 1][j]) + A[i][j];
               
                
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < A[n - 1].size(); i++) {
        ans = min(ans, A[n - 1][i]);
    }
    return ans;
    
    
}
