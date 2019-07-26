void tree(int index, std::vector<std::vector<int> > &ans, std::vector<int> &current_ans, std::vector<int> &A)
{
	if (index >= A.size())
	{
		return;
	}
	while(index < A.size())
	{
		current_ans.push_back(A[index]);
		ans.push_back(current_ans);
        tree(index + 1, ans, current_ans, A);
        current_ans.pop_back();
        index++;
	}

}


vector<vector<int> > Solution::subsetsWithDup(vector<int> &A)
{
	sort(A.begin(), A.end());
    std::vector<std::vector<int> > ans;
    vector<int> a;
    ans.push_back(a);
    std::vector<int> current_ans;
    tree(0, ans, current_ans, A);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}