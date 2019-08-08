void swap(std::vector<int> &A, int i, int start)
{ 
    int temp = A[start];
    A[start] = A[i];
    A[i] = temp;

}

void tree(int start, int end, std::vector<std::vector<int> > &ans, std::vector<int> A)
{
    if(start == end)
    {
        ans.push_back(A);
        return;
    }
    for(int i = start; i <= end; i++)
    {
        swap(A, i, start);
        tree(start + 1, end, ans, A);
        swap(A, start, i);
        
    }
    
}



vector<vector<int> > Solution::permute(vector<int> &A) 
{
    std::vector<std::vector<int> > ans;
    tree(0, A.size() - 1, ans, A);
    return ans;
}
