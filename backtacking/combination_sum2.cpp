void tree(int sum, int index, std::vector<std::vector<int> > &ans, std::vector<int> &current_ans, std::vector<int> &A)
{    
    if(sum == 0)
    {
        ans.push_back(current_ans);
        return;
    }
    if (sum < 0)
    {
        return;
    }

    while ((sum - A[index]) >= 0 && index < A.size())
    {
        current_ans.push_back(A[index]);
        index+=1;
        tree(sum - A[index - 1], index , ans, current_ans, A);
        current_ans.pop_back();
        
    }
    
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) 
{
    sort(A.begin(), A.end());
    int sum = B;
    std::vector<std::vector<int> > ans;
    std::vector<int> current_ans;
    tree(sum, 0, ans, current_ans, A);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}