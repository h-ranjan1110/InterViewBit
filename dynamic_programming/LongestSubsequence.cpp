int Solution::longestSubsequenceLength(const vector<int> &A) 
{
    std::vector<int> increasing(A.size());
    std::vector<int> decreasing(A.size());
    if (A.size() == 0) {
        return 0;
    }
    for (int i = 0; i < A.size(); i++) {
        increasing[i] = 1;
        for (int j = 0 ; j < i ; j++)
        {
            if (A[j] < A[i] && (increasing[j] + 1 > increasing[i]))
            {
                increasing[i] = increasing[j] + 1;
            }
        }
    }

    for (int i = A.size() - 1; i >= 0; i--)
    {
        decreasing[i] = 1;
        for (int j = A.size() - 1; j > i ; j--)
        {
            if (A[i] > A[j] && (decreasing[i] < decreasing[j] + 1))
            {
                decreasing[i] = decreasing[j] + 1;
            }
        }
    }
    int ans = 0;

    for (int i = 0 ; i < A.size(); i++)
    {
        ans = max(ans, increasing[i] + decreasing[i] - 1);
    }
    return ans;
}
