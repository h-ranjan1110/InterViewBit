void tree(int n, vector<int> &ans)
{
    if (n == 1)
    {
        ans.push_back(0);
        ans.push_back(1);
        return;
    }

    tree(n - 1, ans);
    int start = pow(2, n - 1);
    int end = pow(2, n);
    for(int i = start; i < end; i++)
    {
        ans.push_back( pow(2, n - 1) + ans[end - 1 - i]);
    }
    return;
}


vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    std::vector< int >  ans;
    tree(A, ans);
    return ans;

}

