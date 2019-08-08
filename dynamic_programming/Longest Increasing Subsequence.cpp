int Solution::lis(const vector<int> &A) {
    vector<int> lis(A.size());
    int ans = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
            }
        }
        ans = max(ans, lis[i]);
    }
    return ans;
}